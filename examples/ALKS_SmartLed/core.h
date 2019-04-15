
NEW_STATE(off);
NEW_STATE(blinking);
NEW_STATE(learning);
NEW_STATE(learning_on);
NEW_STATE(learning_off);
NEW_STATE(learning_done);

FSM fsm = FSM(off);

bool state = false;
unsigned long time;
unsigned int current_step;
unsigned int steps[STEPS + 1] = {1000, 1000};


// ----------------------------------------------------------------------------

STATE_ENTER(off)
{
    color(RED);
}

STATE_UPDATE(off)
{
    if (fsm.timeInCurrentState() > 500)
    {
        color(BLACK);
    }

    if (btnA.fallingEdge())
    {
        fsm.transitionTo(blinking);
    }

    if (btnB.fallingEdge())
    {
        fsm.transitionTo(learning);
    }
}

STATE_EXIT(off)
{
}

// ----------------------------------------------------------------------------

STATE_ENTER(blinking)
{
    TRACE("Blinking enter");

    current_step = 0;
    state = true;
    time = millis();

    color(WHITE);
}

STATE_UPDATE(blinking)
{
    if (btnA.fallingEdge()) 
    {
        fsm.transitionTo(off);
        return;
    }

    if (btnB.fallingEdge())
    {
        fsm.transitionTo(learning);
        return;
    }

    unsigned int next = steps[current_step];

    if (millis() > time + next)
    {
        TRACE(current_step)

        state = !state;
        if (state)
        {
            color(WHITE);
        }
        else
        {
            color(BLACK);
        }

        current_step++;
        time = millis();

        if (current_step >= STEPS || steps[current_step] == 0) 
        {
            current_step = 0;
        }
    }
}

STATE_EXIT(blinking)
{
}

// ----------------------------------------------------------------------------

STATE_ENTER(learning)
{
    TRACE("lerning_enter");
    current_step = 0;
    color(YELLOW);
}

STATE_UPDATE(learning)
{
    if (fsm.timeInCurrentState() > 500)
    {
        color(BLACK);
    }

    if (btnA.fallingEdge())
    {
        fsm.transitionTo(learning_on);
    }
}

STATE_EXIT(learning)
{
}

// ----------------------------------------------------------------------------

bool save_step()
{
    steps[current_step] = fsm.timeInCurrentState();
    current_step++;

    if (current_step >= STEPS)
    {        
        return false;
    }

    return true;
}


STATE_ENTER(learning_on)
{
    TRACE("lerning_on_enter");
    color(WHITE);
}

STATE_UPDATE(learning_on)
{
    if (btnA.risingEdge())
    {
        if (save_step())
        {
            fsm.transitionTo(learning_off);
        }
        else
        {
            fsm.transitionTo(learning_done);
        }
    }
}

STATE_EXIT(learning_on)
{
}

// ----------------------------------------------------------------------------

STATE_ENTER(learning_off)
{
    TRACE("lerning_off_enter");
    color(BLACK);
}

STATE_UPDATE(learning_off)
{
    if (btnA.fallingEdge())
    {
        if (save_step())
        {
            fsm.transitionTo(learning_on);
        }
        else
        {
            fsm.transitionTo(learning_done);
        }
    }

    if (btnB.fallingEdge()){
        save_step();
        fsm.transitionTo(learning_done);
    }
}

STATE_EXIT(learning_off)
{
}

// ----------------------------------------------------------------------------

STATE_ENTER(learning_done)
{
    TRACE("lerning_done_enter");

    if (current_step < STEPS)
    {
        color(GREEN);
    }
    else
    {
        color(0xFF, 0, 0);    
    }
    
    steps[current_step] = 0;
}

STATE_UPDATE(learning_done)
{
    if (fsm.timeInCurrentState() > 1000)
    {
        color(BLACK);
        fsm.transitionTo(blinking);
    }
}

STATE_EXIT(learning_done)
{
}
