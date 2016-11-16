#include "klasy.hpp"

bool draw = false;
bool draw2 = false;
bool draw_bigger_dice = false;
bool draw_players = false;
bool draw_rolled = false;
bool players3 = false;
bool players4 = false;
bool toss_control = true;
bool sound_control = true;
bool track01_can_play = true;
bool track02_can_play = true;
bool track03_can_play = true;

int main()
{
    PIONEK p1( 1 );
    PIONEK p2( 2 );
    PIONEK p3( 3 );
    PIONEK p4( 4 );
    int current_checker = 1;
    int number_of_players = 0;
    int rolled_value = 0;
    short draw_infoboard = 0;
    short winner = 0;
    short tutorial_guide = 1;
    srand( time( NULL ) );

    bool game_running = true;
    int G_STATE = Menu;

    if( !al_init() )
    {
        al_show_native_message_box( NULL, "Warning", "ERROR", "initialization failed", NULL, 0 );
        return -1;
    }

    ALLEGRO_DISPLAY *main_display = NULL;
    ALLEGRO_MONITOR_INFO aminfo;
    al_get_monitor_info( 0, &aminfo );
    if( al_get_num_video_adapters() == 2 ) { al_set_new_display_adapter( 0 ); al_get_monitor_info( 1, &aminfo ); }
    float desktop_width = aminfo.x2 - aminfo.x1;
    float desktop_height = aminfo.y2 - aminfo.y1;
    std::cout << aminfo.x2 << " " << aminfo.x1 << "\n";
    std::cout << aminfo.y2 << " " << aminfo.y1 << "\n";
    al_set_new_display_flags( ALLEGRO_FULLSCREEN );
    main_display = al_create_display( desktop_width, desktop_height );
    if( !main_display )
    {
        al_show_native_message_box( main_display, "Warning", "ERROR", "display could not be created", NULL, 0 );
        return -1;
    }
    al_set_window_title( main_display, "Gra planszowa" );

    al_init_image_addon();
    al_init_primitives_addon();
    al_init_font_addon(); //to musi byc wczesniej niz ttf addon
    al_init_ttf_addon();
    al_init_acodec_addon();
    al_install_audio();
    al_install_mouse();
    al_install_keyboard();

    ALLEGRO_BITMAP *loadingscr_map = al_load_bitmap( "loadingscr.png" ); //##########################LOADINGSCR
    if( !loadingscr_map )
    {
        al_show_native_message_box( main_display, "Warning", "ERROR",
            "The game could not load. Trust me, it is bad. Contact the developer: gamedevmike@outlook.com", NULL, 0 );
        return -1;
    }
    al_draw_scaled_bitmap( loadingscr_map, 0, 0, 1600, 900, 0, 0, desktop_width , desktop_height, 0 );
    al_flip_display();

    ALLEGRO_BITMAP *menu1_map = al_load_bitmap( "menu1.png" );
    if( !menu1_map )
    {
        al_show_native_message_box( main_display, "Warning", "ERROR", "map could not be loaded", NULL, 0 );
        return -1;
    }
    ALLEGRO_BITMAP *menu2_map = al_load_bitmap( "menu2.png" );
    if( !menu2_map )
    {
        al_show_native_message_box( main_display, "Warning", "ERROR", "map could not be loaded", NULL, 0 );
        return -1;
    }
    ALLEGRO_BITMAP *game_map = al_load_bitmap( "mapa5.png" );
    if( !game_map )
    {
        al_show_native_message_box( main_display, "Warning", "ERROR", "map could not be loaded", NULL, 0 );
        return -1;
    }
    ALLEGRO_BITMAP *game_map2 = al_load_bitmap( "mapa6.png" );
    if( !game_map2 )
    {
        al_show_native_message_box( main_display, "Warning", "ERROR", "map could not be loaded", NULL, 0 );
        return -1;
    }
    ALLEGRO_BITMAP *map_infoboard_2 = al_load_bitmap( "infoboard12.png" );
    if( !map_infoboard_2 )
    {
        al_show_native_message_box( main_display, "Warning", "ERROR", "map could not be loaded", NULL, 0 );
        return -1;
    }
    ALLEGRO_BITMAP *map_infoboard_3 = al_load_bitmap( "infoboard123.png" );
    if( !map_infoboard_3 )
    {
        al_show_native_message_box( main_display, "Warning", "ERROR", "map could not be loaded", NULL, 0 );
        return -1;
    }
    ALLEGRO_BITMAP *map_infoboard_4 = al_load_bitmap( "infoboard1234.png" );
    if( !map_infoboard_4 )
    {
        al_show_native_message_box( main_display, "Warning", "ERROR", "map could not be loaded", NULL, 0 );
        return -1;
    }
    ALLEGRO_BITMAP *map_about = al_load_bitmap( "about_map.png" );
    if( !map_about )
    {
        al_show_native_message_box( main_display, "Warning", "ERROR", "map could not be loaded", NULL, 0 );
        return -1;
    }
    ALLEGRO_BITMAP *map_tut1 = al_load_bitmap( "tutorial1.png" );
    if( !map_tut1 )
    {
        al_show_native_message_box( main_display, "Warning", "ERROR", "map could not be loaded", NULL, 0 );
        return -1;
    }
    ALLEGRO_BITMAP *map_tut2 = al_load_bitmap( "tutorial2.png" );
    if( !map_tut2 )
    {
        al_show_native_message_box( main_display, "Warning", "ERROR", "map could not be loaded", NULL, 0 );
        return -1;
    }
    ALLEGRO_BITMAP *map_tut3 = al_load_bitmap( "tutorial3.png" );
    if( !map_tut3 )
    {
        al_show_native_message_box( main_display, "Warning", "ERROR", "map could not be loaded", NULL, 0 );
        return -1;
    }
    ALLEGRO_BITMAP *map_tut4 = al_load_bitmap( "tutorial4.png" );
    if( !map_tut4 )
    {
        al_show_native_message_box( main_display, "Warning", "ERROR", "map could not be loaded", NULL, 0 );
        return -1;
    }
    ALLEGRO_BITMAP *map_tut5 = al_load_bitmap( "tutorial5.png" );
    if( !map_tut5 )
    {
        al_show_native_message_box( main_display, "Warning", "ERROR", "map could not be loaded", NULL, 0 );
        return -1;
    }
    ALLEGRO_BITMAP *map_tut6 = al_load_bitmap( "tutorial_ready.png" );
    if( !map_tut6 )
    {
        al_show_native_message_box( main_display, "Warning", "ERROR", "map could not be loaded", NULL, 0 );
        return -1;
    }
    ALLEGRO_BITMAP *map_pause = al_load_bitmap( "interrupted.png" );
    if( !map_pause )
    {
        al_show_native_message_box( main_display, "Warning", "ERROR", "map could not be loaded", NULL, 0 );
        return -1;
    }
    ALLEGRO_BITMAP *cursor_map = al_load_bitmap( "cursor4.png" );
    ALLEGRO_FONT *font1 = al_load_font( "BEBAS___.ttf", 48, 0 );
    ALLEGRO_FONT *font2 = al_load_font( "BEBAS___.ttf", 50, 0 );
    ALLEGRO_FONT *font3 = al_load_font( "BEBAS___.ttf", 24, 0 );
    ALLEGRO_FONT *font4 = al_load_font( "BEBAS___.ttf", 34, 0 );
    ALLEGRO_COLOR menu_black = al_map_rgb( 0, 0, 0 );
    ALLEGRO_COLOR menu_hover = al_map_rgb( 107, 107, 107 );
    ALLEGRO_COLOR menu_current1 = menu_black;
    ALLEGRO_COLOR menu_current2 = menu_black;
    ALLEGRO_COLOR menu_current3 = menu_black;
    ALLEGRO_COLOR menu_current4 = menu_black;
    ALLEGRO_MOUSE_CURSOR *cursor1 = al_create_mouse_cursor( cursor_map , 0, 0 );
    al_set_mouse_cursor( main_display, cursor1 );
    //al_show_mouse_cursor( main_display );
    ALLEGRO_SAMPLE *sf_dice_toss = al_load_sample( "sf_dice_0.wav" );
    ALLEGRO_SAMPLE *sf_moving = al_load_sample( "sf_moving.wav" );
    ALLEGRO_SAMPLE *sf_denied = al_load_sample( "sf_denied.wav" );
    ALLEGRO_SAMPLE *track01 = al_load_sample( "track01_menu.ogg" );
    ALLEGRO_SAMPLE *track02 = al_load_sample( "track02_game.ogg" );
    ALLEGRO_SAMPLE *track03 = al_load_sample( "track03_tutorial.ogg" );
    al_reserve_samples( 6 );
    ALLEGRO_SAMPLE_INSTANCE *track01_instance = al_create_sample_instance( track01 );
    ALLEGRO_SAMPLE_INSTANCE *track02_instance = al_create_sample_instance( track02 );
    ALLEGRO_SAMPLE_INSTANCE *track03_instance = al_create_sample_instance( track03 );
    al_set_sample_instance_playmode( track01_instance, ALLEGRO_PLAYMODE_LOOP );
    al_set_sample_instance_playmode( track02_instance, ALLEGRO_PLAYMODE_LOOP );
    al_set_sample_instance_playmode( track03_instance, ALLEGRO_PLAYMODE_LOOP );
    al_attach_sample_instance_to_mixer( track01_instance, al_get_default_mixer() );
    al_attach_sample_instance_to_mixer( track02_instance, al_get_default_mixer() );
    al_attach_sample_instance_to_mixer( track03_instance, al_get_default_mixer() );

    ALLEGRO_TIMER *timer1 = al_create_timer( 1.0 / 60.0 );
    ALLEGRO_EVENT_QUEUE *event_q1 = al_create_event_queue();
    al_register_event_source( event_q1, al_get_timer_event_source( timer1 ) );
    al_register_event_source( event_q1, al_get_mouse_event_source() );
    al_register_event_source( event_q1, al_get_keyboard_event_source() );
    ALLEGRO_EVENT events;

    al_start_timer( timer1 );

    while( game_running ) //###################################################################MAIN_LOOP
    {
        al_wait_for_event( event_q1, &events );

        if( G_STATE == Menu ) //##########################################################MENU
        {
            if( events.type == ALLEGRO_EVENT_KEY_DOWN )
            {
                switch( events.keyboard.keycode )
                {
                    case ALLEGRO_KEY_ESCAPE: {
                        //game_running = false;
                        menu_current1 = menu_black;
                        menu_current2 = menu_black;
                        menu_current3 = menu_black;
                        menu_current4 = menu_black; break; }
                }
            }
            else if( events.type == ALLEGRO_EVENT_MOUSE_AXES )
            {
                if( events.mouse.x > 0.1*desktop_width && events.mouse.x < 0.1*desktop_width+242
                    && events.mouse.y > (420.0/900.0)*desktop_height && events.mouse.y < (420.0/900.0)*desktop_height+48 )
                    menu_current1 = menu_hover;
                else menu_current1 = menu_black;

                if( events.mouse.x > 0.1*desktop_width && events.mouse.x < 0.1*desktop_width+196
                    && events.mouse.y > (510.0/900.0)*desktop_height && events.mouse.y < (510.0/900.0)*desktop_height+48 )
                    menu_current2 = menu_hover;
                else menu_current2 = menu_black;

                if( events.mouse.x > 0.1*desktop_width && events.mouse.x < 0.1*desktop_width+134
                    && events.mouse.y > (600.0/900.0)*desktop_height && events.mouse.y < (600.0/900.0)*desktop_height+48 )
                    menu_current3 = menu_hover;
                else menu_current3 = menu_black;

                if( events.mouse.x > 0.1*desktop_width && events.mouse.x < 0.1*desktop_width+90
                    && events.mouse.y > (690.0/900.0)*desktop_height && events.mouse.y < (690.0/900.0)*desktop_height+48 )
                    menu_current4 = menu_hover;
                else menu_current4 = menu_black;
            }
            else if( events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN )
            {
                if( events.mouse.button & 1
                    && events.mouse.x > 0.1*desktop_width && events.mouse.x < 0.1*desktop_width+242
                    && events.mouse.y > (420.0/900.0)*desktop_height && events.mouse.y < (420.0/900.0)*desktop_height+48 )
                    {
                        p1.set_player_position( 0 );
                        p2.set_player_position( 0 );
                        p3.set_player_position( 0 );
                        p4.set_player_position( 0 );
                        current_checker = 1;
                        players3 = false;
                        players4 = false;
                        G_STATE = Players;
                    }
                else if( events.mouse.button & 1
                    && events.mouse.x > 0.1*desktop_width && events.mouse.x < 0.1*desktop_width+196
                    && events.mouse.y > (510.0/900.0)*desktop_height && events.mouse.y < (510.0/900.0)*desktop_height+48 )
                    { tutorial_guide = 1; track03_can_play = true; G_STATE = Tutorial; }
                else if( events.mouse.button & 1
                    && events.mouse.x > 0.1*desktop_width && events.mouse.x < 0.1*desktop_width+134
                    && events.mouse.y > (600.0/900.0)*desktop_height && events.mouse.y < (600.0/900.0)*desktop_height+48 )
                    G_STATE = About;
                else if( events.mouse.button & 1
                    && events.mouse.x > 0.1*desktop_width && events.mouse.x < 0.1*desktop_width+90
                    && events.mouse.y > (690.0/900.0)*desktop_height && events.mouse.y < (690.0/900.0)*desktop_height+48 )
                    game_running = false;
            }
            if( events.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP )
            {
                menu_current1 = menu_black;
                menu_current2 = menu_black;
                menu_current3 = menu_black;
                menu_current4 = menu_black;
            }

            if( track01_can_play )
            {
                al_stop_sample_instance( track02_instance );
                al_stop_sample_instance( track03_instance );
                al_play_sample_instance( track01_instance );
                track01_can_play = false;
            }
            al_draw_scaled_bitmap( menu1_map, 0, 0, 1600, 900, 0, 0, desktop_width , desktop_height, 0 );
            al_draw_text( font1, menu_current1, 0.1*desktop_width, (410.0/900.0)*desktop_height, 0, "START GAME" );
            al_draw_text( font1, menu_current2, 0.1*desktop_width, (500.0/900.0)*desktop_height, 0, "TUTORIAL" );
            al_draw_text( font1, menu_current3, 0.1*desktop_width, (590.0/900.0)*desktop_height, 0, "ABOUT" );
            al_draw_text( font1, menu_current4, 0.1*desktop_width, (680.0/900.0)*desktop_height, 0, "EXIT" );
            al_flip_display();
        }
        else if( G_STATE == Tutorial ) //####################################################TUTORIAL
        {
            if( track03_can_play )
            {
                al_stop_sample_instance( track01_instance );
                al_play_sample_instance( track03_instance );
                track03_can_play = false;
            }

            if( tutorial_guide == 1 )
            {
                if( events.type == ALLEGRO_EVENT_KEY_DOWN )
                    switch( events.keyboard.keycode ) case ALLEGRO_KEY_ESCAPE: { track01_can_play = true; G_STATE = Menu; break; }
                if( events.type == ALLEGRO_EVENT_MOUSE_AXES )
                {
                    if( events.mouse.x > (1450.0/1600.0)*desktop_width && events.mouse.x < (1450.0/1600.0)*desktop_width+74
                        && events.mouse.y > (30.0/900.0)*desktop_height && events.mouse.y < (30.0/900.0)*desktop_height+34 )
                        menu_current1 = menu_hover;
                    else menu_current1 = menu_black;
                }
                if( events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN )
                {
                    if( events.mouse.button & 1
                        && events.mouse.x > (1450.0/1600.0)*desktop_width && events.mouse.x < (1450.0/1600.0)*desktop_width+74
                        && events.mouse.y > (30.0/900.0)*desktop_height && events.mouse.y < (30.0/900.0)*desktop_height+34 )
                        tutorial_guide = 2;
                }
                if( events.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP )
                {
                    menu_current1 = menu_black;
                }
                al_draw_scaled_bitmap( map_tut1, 0, 0, 1600, 900, 0, 0, desktop_width , desktop_height, 0 );
                al_draw_text( font4, menu_current1, (1450.0/1600.0)*desktop_width, (20.0/900.0)*desktop_height, 0, "NEXT" );
                al_flip_display();
            }
            else if( tutorial_guide == 2 )
            {
                if( events.type == ALLEGRO_EVENT_KEY_DOWN )
                    switch( events.keyboard.keycode ) case ALLEGRO_KEY_ESCAPE: { track01_can_play = true; G_STATE = Menu; break; }
                if( events.type == ALLEGRO_EVENT_MOUSE_AXES )
                {
                    if( events.mouse.x > (1450.0/1600.0)*desktop_width && events.mouse.x < (1450.0/1600.0)*desktop_width+74
                        && events.mouse.y > (30.0/900.0)*desktop_height && events.mouse.y < (30.0/900.0)*desktop_height+34 )
                        menu_current1 = menu_hover;
                    else menu_current1 = menu_black;

                    if( events.mouse.x > (1320.0/1600.0)*desktop_width && events.mouse.x < (1320.0/1600.0)*desktop_width+74
                        && events.mouse.y > (30.0/900.0)*desktop_height && events.mouse.y < (30.0/900.0)*desktop_height+34 )
                        menu_current2 = menu_hover;
                    else menu_current2 = menu_black;
                }
                if( events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN )
                {
                    if( events.mouse.button & 1
                        && events.mouse.x > (1450.0/1600.0)*desktop_width && events.mouse.x < (1450.0/1600.0)*desktop_width+74
                        && events.mouse.y > (30.0/900.0)*desktop_height && events.mouse.y < (30.0/900.0)*desktop_height+34 )
                        tutorial_guide = 3;

                    if( events.mouse.button & 1
                        && events.mouse.x > (1320.0/1600.0)*desktop_width && events.mouse.x < (1320.0/1600.0)*desktop_width+74
                        && events.mouse.y > (30.0/900.0)*desktop_height && events.mouse.y < (30.0/900.0)*desktop_height+34 )
                        tutorial_guide = 1;
                }
                if( events.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP )
                {
                    menu_current1 = menu_black;
                    menu_current2 = menu_black;
                }
                al_draw_scaled_bitmap( map_tut2, 0, 0, 1600, 900, 0, 0, desktop_width , desktop_height, 0 );
                al_draw_text( font4, menu_current1, (1450.0/1600.0)*desktop_width, (20.0/900.0)*desktop_height, 0, "NEXT" );
                al_draw_text( font4, menu_current2, (1320.0/1600.0)*desktop_width, (20.0/900.0)*desktop_height, 0, "BACK" );
                al_flip_display();
            }
            else if( tutorial_guide == 3 )
            {
                if( events.type == ALLEGRO_EVENT_KEY_DOWN )
                    switch( events.keyboard.keycode ) case ALLEGRO_KEY_ESCAPE: { track01_can_play = true; G_STATE = Menu; break; }
                if( events.type == ALLEGRO_EVENT_MOUSE_AXES )
                {
                    if( events.mouse.x > (1320.0/1600.0)*desktop_width && events.mouse.x < (1320.0/1600.0)*desktop_width+74
                        && events.mouse.y > (30.0/900.0)*desktop_height && events.mouse.y < (30.0/900.0)*desktop_height+34 )
                        menu_current2 = menu_hover;
                    else menu_current2 = menu_black;
                }
                if( events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN )
                {
                    if( events.mouse.button & 1
                        && events.mouse.x > (1320.0/1600.0)*desktop_width && events.mouse.x < (1320.0/1600.0)*desktop_width+74
                        && events.mouse.y > (30.0/900.0)*desktop_height && events.mouse.y < (30.0/900.0)*desktop_height+34 )
                        tutorial_guide = 2;

                    if( events.mouse.button & 1
                        && events.mouse.x >= (80.0/1600.0)*desktop_width && events.mouse.x <= (230.0/1600.0)*desktop_width
                        && events.mouse.y >= (680.0/900.0)*desktop_height && events.mouse.y <= (820.0/900.0)*desktop_height )
                        {
                            al_play_sample( sf_dice_toss, 1.3, 0.0, 1.2, ALLEGRO_PLAYMODE_ONCE, 0 );
                            tutorial_guide = 4;
                        }
                }
                if( events.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP )
                {
                    menu_current2 = menu_black;
                }
                al_draw_scaled_bitmap( map_tut3, 0, 0, 1600, 900, 0, 0, desktop_width , desktop_height, 0 );
                al_draw_text( font4, menu_current2, (1320.0/1600.0)*desktop_width, (20.0/900.0)*desktop_height, 0, "BACK" );
                al_flip_display();
            }
            else if( tutorial_guide == 4 )
            {
                if( events.type == ALLEGRO_EVENT_KEY_DOWN )
                    switch( events.keyboard.keycode ) case ALLEGRO_KEY_ESCAPE: { track01_can_play = true; G_STATE = Menu; break; }
                if( events.type == ALLEGRO_EVENT_MOUSE_AXES )
                {
                    if( events.mouse.x > (1320.0/1600.0)*desktop_width && events.mouse.x < (1320.0/1600.0)*desktop_width+74
                        && events.mouse.y > (30.0/900.0)*desktop_height && events.mouse.y < (30.0/900.0)*desktop_height+34 )
                        menu_current2 = menu_hover;
                    else menu_current2 = menu_black;
                }
                if( events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN )
                {
                    if( events.mouse.button & 1
                        && events.mouse.x > (1320.0/1600.0)*desktop_width && events.mouse.x < (1320.0/1600.0)*desktop_width+74
                        && events.mouse.y > (30.0/900.0)*desktop_height && events.mouse.y < (30.0/900.0)*desktop_height+34 )
                        tutorial_guide = 2;

                    if( events.mouse.button & 1
                        && ( events.mouse.x > (1145.0/1600.0)*desktop_width && events.mouse.x < (1560.0/1600.0)*desktop_width
                        && events.mouse.y > (400.0/900.0)*desktop_height && events.mouse.y < (500.0/900.0)*desktop_height ) )
                        {
                            al_play_sample( sf_moving, 1.2, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0 );
                            tutorial_guide = 5;
                        }
                }
                if( events.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP )
                {
                    menu_current2 = menu_black;
                }
                al_draw_scaled_bitmap( map_tut4, 0, 0, 1600, 900, 0, 0, desktop_width , desktop_height, 0 );
                al_draw_text( font4, menu_current2, (1320.0/1600.0)*desktop_width, (20.0/900.0)*desktop_height, 0, "BACK" );
                al_flip_display();
            }
            else if( tutorial_guide == 5 )
            {
                if( events.type == ALLEGRO_EVENT_KEY_DOWN )
                    switch( events.keyboard.keycode ) case ALLEGRO_KEY_ESCAPE: { track01_can_play = true; G_STATE = Menu; break; }
                if( events.type == ALLEGRO_EVENT_MOUSE_AXES )
                {
                    if( events.mouse.x > (1450.0/1600.0)*desktop_width && events.mouse.x < (1450.0/1600.0)*desktop_width+74
                        && events.mouse.y > (30.0/900.0)*desktop_height && events.mouse.y < (30.0/900.0)*desktop_height+34 )
                        menu_current1 = menu_hover;
                    else menu_current1 = menu_black;

                    if( events.mouse.x > (1320.0/1600.0)*desktop_width && events.mouse.x < (1320.0/1600.0)*desktop_width+74
                        && events.mouse.y > (30.0/900.0)*desktop_height && events.mouse.y < (30.0/900.0)*desktop_height+34 )
                        menu_current2 = menu_hover;
                    else menu_current2 = menu_black;
                }
                if( events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN )
                {
                    if( events.mouse.button & 1
                        && events.mouse.x > (1450.0/1600.0)*desktop_width && events.mouse.x < (1450.0/1600.0)*desktop_width+74
                        && events.mouse.y > (30.0/900.0)*desktop_height && events.mouse.y < (30.0/900.0)*desktop_height+34 )
                        tutorial_guide = 6;

                    if( events.mouse.button & 1
                        && events.mouse.x > (1320.0/1600.0)*desktop_width && events.mouse.x < (1320.0/1600.0)*desktop_width+74
                        && events.mouse.y > (30.0/900.0)*desktop_height && events.mouse.y < (30.0/900.0)*desktop_height+34 )
                        tutorial_guide = 3;
                }
                if( events.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP )
                {
                    menu_current1 = menu_black;
                    menu_current2 = menu_black;
                }
                al_draw_scaled_bitmap( map_tut5, 0, 0, 1600, 900, 0, 0, desktop_width , desktop_height, 0 );
                al_draw_text( font4, menu_current1, (1450.0/1600.0)*desktop_width, (20.0/900.0)*desktop_height, 0, "NEXT" );
                al_draw_text( font4, menu_current2, (1320.0/1600.0)*desktop_width, (20.0/900.0)*desktop_height, 0, "BACK" );
                al_flip_display();
            }
            else if( tutorial_guide == 6 )
            {
                if( events.type == ALLEGRO_EVENT_KEY_DOWN )
                    switch( events.keyboard.keycode ) case ALLEGRO_KEY_ESCAPE: { track01_can_play = true; G_STATE = Menu; break; }
                if( events.type == ALLEGRO_EVENT_MOUSE_AXES )
                {
                    if( events.mouse.x > (100.0/1600.0)*desktop_width && events.mouse.x < (100.0/1600.0)*desktop_width+252
                        && events.mouse.y > (410.0/900.0)*desktop_height && events.mouse.y < (410.0/900.0)*desktop_height+50 )
                        menu_current1 = menu_hover;
                    else menu_current1 = menu_black;

                    if( events.mouse.x > (100.0/1600.0)*desktop_width && events.mouse.x < (100.0/1600.0)*desktop_width+288
                        && events.mouse.y > (510.0/900.0)*desktop_height && events.mouse.y < (510.0/900.0)*desktop_height+50 )
                        menu_current2 = menu_hover;
                    else menu_current2 = menu_black;
                }
                if( events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN )
                {
                    if( events.mouse.button & 1
                        && events.mouse.x > (100.0/1600.0)*desktop_width && events.mouse.x < (100.0/1600.0)*desktop_width+252
                        && events.mouse.y > (410.0/900.0)*desktop_height && events.mouse.y < (410.0/900.0)*desktop_height+50 )
                        {
                            p1.set_player_position( 0 );
                            p2.set_player_position( 0 );
                            p3.set_player_position( 0 );
                            p4.set_player_position( 0 );
                            current_checker = 1;
                            players3 = false;
                            players4 = false;
                            G_STATE = Players;
                        }

                    if( events.mouse.button & 1
                        && events.mouse.x > (100.0/1600.0)*desktop_width && events.mouse.x < (100.0/1600.0)*desktop_width+288
                        && events.mouse.y > (510.0/900.0)*desktop_height && events.mouse.y < (510.0/900.0)*desktop_height+50 )
                        { track01_can_play = true; G_STATE = Menu; }
                }
                if( events.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP )
                {
                    menu_current1 = menu_black;
                    menu_current2 = menu_black;
                }
                al_draw_scaled_bitmap( map_tut6, 0, 0, 1600, 900, 0, 0, desktop_width , desktop_height, 0 );
                al_draw_text( font2, menu_current1, (100.0/1600.0)*desktop_width, (400.0/900.0)*desktop_height, 0, "START GAME" );
                al_draw_text( font2, menu_current2, (100.0/1600.0)*desktop_width, (500.0/900.0)*desktop_height, 0, "BACK TO MENU" );
                al_flip_display();
            }
        }
        else if( G_STATE == About ) //#########################################################ABOUT
        {
            if( events.type == ALLEGRO_EVENT_KEY_DOWN ) switch( events.keyboard.keycode ) { case ALLEGRO_KEY_ESCAPE: { G_STATE = Menu; break; } }
            if( events.type == ALLEGRO_EVENT_MOUSE_AXES )
            {
                if( events.mouse.x > 0.04*desktop_width && events.mouse.x < 0.04*desktop_width+104
                    && events.mouse.y > (790.0/900.0)*desktop_height && events.mouse.y < (790.0/900.0)*desktop_height+48 )
                    menu_current1 = menu_hover;
                else menu_current1 = menu_black;
            }
            if( events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN )
            {
                if( events.mouse.button & 1
                    && events.mouse.x > 0.04*desktop_width && events.mouse.x < 0.04*desktop_width+104
                    && events.mouse.y > (790.0/900.0)*desktop_height && events.mouse.y < (790.0/900.0)*desktop_height+48 )
                    G_STATE = Menu;
            }

            al_draw_scaled_bitmap( map_about, 0, 0, 1600, 900, 0, 0, desktop_width , desktop_height, 0 );
            al_draw_text( font1, menu_current1, 0.04*desktop_width, (780.0/900.0)*desktop_height, 0, "BACK" );
            al_flip_display();
        }
        else if( G_STATE == Players ) //#####################################################PLAYERS
        {
            if( events.type == ALLEGRO_EVENT_KEY_DOWN )
            {
                switch( events.keyboard.keycode )
                {
                    case ALLEGRO_KEY_ESCAPE: { G_STATE = Menu; break; }
                }
            }
            else if( events.type == ALLEGRO_EVENT_MOUSE_AXES )
            {
                if( events.mouse.x > 0.1*desktop_width && events.mouse.x < 0.45*desktop_height
                    && events.mouse.y > 0.2*desktop_height && events.mouse.y < 0.2*desktop_height+56 )
                    menu_current1 = menu_hover;
                else menu_current1 = menu_black;

                if( events.mouse.x > 0.2*desktop_width && events.mouse.x < 0.63*desktop_height
                    && events.mouse.y > 0.35*desktop_height && events.mouse.y < 0.35*desktop_height+56 )
                    menu_current2 = menu_hover;
                else menu_current2 = menu_black;

                if( events.mouse.x > 0.3*desktop_width && events.mouse.x < 0.81*desktop_height
                    && events.mouse.y > 0.5*desktop_height && events.mouse.y < 0.5*desktop_height+56 )
                    menu_current3 = menu_hover;
                else menu_current3 = menu_black;
            }
            else if( events.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP )
                if( events.mouse.button & 1 )
                {
                    draw_players = true;
                    menu_current1 = menu_black;
                }
            if( events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN )
            {
                if( events.mouse.button & 1
                    && events.mouse.x > 0.1*desktop_width && events.mouse.x < 0.45*desktop_height
                    && events.mouse.y > 0.2*desktop_height && events.mouse.y < 0.2*desktop_height+56 )
                    {
                        G_STATE = Game;
                        number_of_players = 2;
                        draw_infoboard = 1;
                        track02_can_play = true;
                    }

                else if( events.mouse.button & 1
                    && events.mouse.x > 0.2*desktop_width && events.mouse.x < 0.63*desktop_height
                    && events.mouse.y > 0.35*desktop_height && events.mouse.y < 0.35*desktop_height+56 )
                    {
                        G_STATE = Game;
                        players3 = true;
                        number_of_players = 3;
                        draw_infoboard = 2;
                        track02_can_play = true;
                    }
                else if( events.mouse.button & 1
                    && events.mouse.x > 0.3*desktop_width && events.mouse.x < 0.81*desktop_height
                    && events.mouse.y > 0.5*desktop_height && events.mouse.y < 0.5*desktop_height+56 )
                    {
                        G_STATE = Game;
                        players3 = true;
                        players4 = true;
                        number_of_players = 4;
                        draw_infoboard = 3;
                        track02_can_play = true;
                    }
            }

            if( draw_players )
            {
                al_draw_scaled_bitmap( menu1_map, 0, 0, 1600, 900, 0, 0, desktop_width , desktop_height, 0 );
                al_draw_text( font1, menu_current1, 0.1*desktop_width, 0.2*desktop_height, 0, "2   PLAYERS" );
                al_draw_text( font1, menu_current2, 0.2*desktop_width, 0.35*desktop_height, 0, "3   PLAYERS" );
                al_draw_text( font1, menu_current3, 0.3*desktop_width, 0.5*desktop_height, 0, "4   PLAYERS" );
            }
            al_flip_display();
        }
        else if( G_STATE == Game ) //##########################################################GAME
        {
            if( events.type == ALLEGRO_EVENT_KEY_DOWN )
                switch( events.keyboard.keycode ) { case ALLEGRO_KEY_ESCAPE: { track01_can_play = true; G_STATE = Pause; break; } }

            else if( events.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP )
                if( events.mouse.button & 1 ) draw = true;

            if( events.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP ) //DICE TOSS
            {
                if( toss_control == true && events.mouse.button & 1
                   && events.mouse.x >= (80.0/1600.0)*desktop_width && events.mouse.x <= (230.0/1600.0)*desktop_width
                   && events.mouse.y >= (680.0/900.0)*desktop_height && events.mouse.y <= (820.0/900.0)*desktop_height )
                    {
                        al_play_sample( sf_dice_toss, 1.3, 0.0, 1.2, ALLEGRO_PLAYMODE_ONCE, 0 );
                        rolled_value = ( rand() % 4 ) + 1;
                        draw_rolled = true;
                        toss_control = false;
                        /*if( number_of_players == 2 )
                        {
                            if( current_checker == 1 ) { p1.move_player( rolled_value ); current_checker++; }
                            else if( current_checker == 2 ) { p2.move_player( rolled_value ); current_checker--; }
                        }
                        else if( number_of_players == 3 )
                        {
                            if( current_checker == 1 ) { p1.move_player( rolled_value ); current_checker++; }
                            else if( current_checker == 2 ) { p2.move_player( rolled_value ); current_checker++; }
                            else if( current_checker == 3 ) { p3.move_player( rolled_value ); current_checker = 1; }
                        }
                        else if( number_of_players == 4 )
                        {
                            if( current_checker == 1 ) { p1.move_player( rolled_value ); current_checker++; }
                            else if( current_checker == 2 ) { p2.move_player( rolled_value ); current_checker++; }
                            else if( current_checker == 3 ) { p3.move_player( rolled_value ); current_checker++; }
                            else if( current_checker == 4 ) { p4.move_player( rolled_value ); current_checker = 1; }
                        } */
                    }

                if( draw_rolled == true && events.mouse.button & 1
                   && ( events.mouse.x > (1145.0/1600.0)*desktop_width && events.mouse.x < (1560.0/1600.0)*desktop_width
                   && events.mouse.y > (400.0/900.0)*desktop_height && events.mouse.y < (500.0/900.0)*desktop_height ) )
                    {
                        draw_rolled = false;
                        if( number_of_players == 2 )
                        {
                            if( current_checker == 1 ) { sound_control = p1.move_player( rolled_value ); current_checker++; }
                            else if( current_checker == 2 ) { sound_control = p2.move_player( rolled_value ); current_checker--; }
                        }
                        else if( number_of_players == 3 )
                        {
                            if( current_checker == 1 ) { sound_control = p1.move_player( rolled_value ); current_checker++; }
                            else if( current_checker == 2 ) { sound_control = p2.move_player( rolled_value ); current_checker++; }
                            else if( current_checker == 3 ) { sound_control = p3.move_player( rolled_value ); current_checker = 1; }
                        }
                        else if( number_of_players == 4 )
                        {
                            if( current_checker == 1 ) { sound_control = p1.move_player( rolled_value ); current_checker++; }
                            else if( current_checker == 2 ) { sound_control = p2.move_player( rolled_value ); current_checker++; }
                            else if( current_checker == 3 ) { sound_control = p3.move_player( rolled_value ); current_checker++; }
                            else if( current_checker == 4 ) { sound_control = p4.move_player( rolled_value ); current_checker = 1; }
                        }
                        if( sound_control ) al_play_sample( sf_moving, 1.2, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0 );
                        else al_play_sample( sf_denied, 0.6, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0 );

                        toss_control = true;
                    }
            }
            draw_bigger_dice = false;
            if( events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN )
            {
                if( events.mouse.button & 1
                   && events.mouse.x >= (80.0/1600.0)*desktop_width && events.mouse.x <= (230.0/1600.0)*desktop_width
                   && events.mouse.y >= (680.0/900.0)*desktop_height && events.mouse.y <= (820.0/900.0)*desktop_height )
                   draw_bigger_dice = true;
            }

            if( track02_can_play )
            {
                al_stop_sample_instance( track01_instance );
                al_stop_sample_instance( track03_instance );
                al_play_sample_instance( track02_instance );
                track02_can_play = false;
            }
            if( draw ) al_draw_scaled_bitmap( game_map, 0, 0, 1600, 900, 0, 0, desktop_width , desktop_height, 0 );
            if( draw_bigger_dice ) al_draw_scaled_bitmap( game_map2, 0, 0, 1600, 900, 0, 0, desktop_width , desktop_height, 0 );

            if( draw_infoboard == 1 ) al_draw_scaled_bitmap( map_infoboard_2, 0, 0, 400, 270, (1152.0/1600.0)*desktop_width, (505.0/900.0)*desktop_height, (400.0/1600.0)*desktop_width , (270.0/900.0)*desktop_height, 0 );
            else if( draw_infoboard == 2 ) al_draw_scaled_bitmap( map_infoboard_3, 0, 0, 400, 270, (1152.0/1600.0)*desktop_width, (505.0/900.0)*desktop_height, (400.0/1600.0)*desktop_width , (270.0/900.0)*desktop_height, 0 );
            else if( draw_infoboard == 3 ) al_draw_scaled_bitmap( map_infoboard_4, 0, 0, 400, 270, (1152.0/1600.0)*desktop_width, (505.0/900.0)*desktop_height, (400.0/1600.0)*desktop_width , (270.0/900.0)*desktop_height, 0 );
            else return -1;


            if( draw_rolled )
            {
                switch( rolled_value )
                {
                case 1: { /* al_draw_scaled_bitmap( map_dice_toss_1, 0, 0, 400, 100,
                    (1150.0/1600.0)*desktop_width, (400.0/900.0)*desktop_height,
                    (400.0/1600)*desktop_width, (100.0/900.0)*desktop_height, 0 ); */
                    al_draw_text( font2, al_map_rgb( 0, 0, 0 ), (1495.0/1600.0)*desktop_width, (412.0/900.0)*desktop_height, 0, "1" );
                    break; }
                case 2: { /* al_draw_scaled_bitmap( map_dice_toss_2, 0, 0, 400, 100,
                    (1150.0/1600.0)*desktop_width, (400.0/900.0)*desktop_height,
                    (400.0/1600)*desktop_width, (100.0/900.0)*desktop_height, 0 ); */
                    al_draw_text( font2, al_map_rgb( 0, 0, 0 ), (1495.0/1600.0)*desktop_width, (412.0/900.0)*desktop_height, 0, "2" );
                    break; }
                case 3: { /* al_draw_scaled_bitmap( map_dice_toss_3, 0, 0, 400, 100,
                    (1150.0/1600.0)*desktop_width, (400.0/900.0)*desktop_height,
                    (400.0/1600)*desktop_width, (100.0/900.0)*desktop_height, 0 ); */
                    al_draw_text( font2, al_map_rgb( 0, 0, 0 ), (1495.0/1600.0)*desktop_width, (412.0/900.0)*desktop_height, 0, "3" );
                    break; }
                case 4: { /* al_draw_scaled_bitmap( map_dice_toss_4, 0, 0, 400, 100,
                    (1150.0/1600.0)*desktop_width, (400.0/900.0)*desktop_height,
                    (400.0/1600)*desktop_width, (100.0/900.0)*desktop_height, 0 ); */
                    al_draw_text( font2, al_map_rgb( 0, 0, 0 ), (1495.0/1600.0)*desktop_width, (412.0/900.0)*desktop_height, 0, "4" );
                    break; }
                }
            }

            p1.draw_checker( desktop_width, desktop_height );
            p1.draw_position( font3, desktop_width, desktop_height );
            p2.draw_checker( desktop_width, desktop_height );
            p2.draw_position( font3, desktop_width, desktop_height );
            if( players3 )
            {
                p3.draw_checker( desktop_width, desktop_height );
                p3.draw_position( font3, desktop_width, desktop_height );
            }
            if( players4 )
            {
                p4.draw_checker( desktop_width, desktop_height );
                p4.draw_position( font3, desktop_width, desktop_height );
            }


            if( p1.check_finished_game() ) //#########FINISH_CHECKING
            {
                winner = 1;
                al_draw_text( font3, al_map_rgb( 0, 0, 0 ),
                    (440.0/1600.0)*desktop_width, (830.0/900.0)*desktop_height, 0,
                    "CONGRATULATIONS,  CLICK  ANYWHERE  TO  CLAIM  VICTORY,  RED  ONE" );
                if( events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN ) G_STATE = End;
            }
            else if( p2.check_finished_game() )
            {
                winner = 2;
                al_draw_text( font3, al_map_rgb( 0, 0, 0 ),
                    (440.0/1600.0)*desktop_width, (830.0/900.0)*desktop_height, 0,
                    "CONGRATULATIONS,  CLICK  ANYWHERE  TO  CLAIM  VICTORY,  GREEN  ONE" );
                if( events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN ) G_STATE = End;
            }
            else if( p3.check_finished_game() )
            {
                winner = 3;
                al_draw_text( font3, al_map_rgb( 0, 0, 0 ),
                    (440.0/1600.0)*desktop_width, (830.0/900.0)*desktop_height, 0,
                    "CONGRATULATIONS,  CLICK  ANYWHERE  TO  CLAIM  VICTORY,  YELLOW  ONE" );
                if( events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN ) G_STATE = End;
            }
            else if( p4.check_finished_game() )
            {
                winner = 4;
                al_draw_text( font3, al_map_rgb( 0, 0, 0 ),
                    (440.0/1600.0)*desktop_width, (830.0/900.0)*desktop_height, 0,
                    "CONGRATULATIONS,  CLICK  ANYWHERE  TO  CLAIM  VICTORY,  BLUE  ONE" );
                if( events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN ) G_STATE = End;
            }
            al_flip_display();
        }
        else if( G_STATE == Pause ) //######################################################PAUSE
        {
            if( events.type == ALLEGRO_EVENT_KEY_DOWN ) switch( events.keyboard.keycode ) { case ALLEGRO_KEY_ESCAPE: { track02_can_play = true; G_STATE = Game; break; } }
            if( events.type == ALLEGRO_EVENT_MOUSE_AXES )
            {
                if( events.mouse.x > (100.0/1600.0)*desktop_width && events.mouse.x < (100.0/1600.0)*desktop_width+234
                    && events.mouse.y > (410.0/900.0)*desktop_height && events.mouse.y < (410.0/900.0)*desktop_height+50 )
                    menu_current1 = menu_hover;
                else menu_current1 = menu_black;

                if( events.mouse.x > (100.0/1600.0)*desktop_width && events.mouse.x < (100.0/1600.0)*desktop_width+288
                    && events.mouse.y > (510.0/900.0)*desktop_height && events.mouse.y < (510.0/900.0)*desktop_height+50 )
                    menu_current2 = menu_hover;
                else menu_current2 = menu_black;
            }
            if( events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN )
            {
                if( events.mouse.button & 1
                    && events.mouse.x > (100.0/1600.0)*desktop_width && events.mouse.x < (100.0/1600.0)*desktop_width+234
                    && events.mouse.y > (410.0/900.0)*desktop_height && events.mouse.y < (410.0/900.0)*desktop_height+50 )
                    G_STATE = Menu;

                if( events.mouse.button & 1
                    && events.mouse.x > (100.0/1600.0)*desktop_width && events.mouse.x < (100.0/1600.0)*desktop_width+288
                    && events.mouse.y > (510.0/900.0)*desktop_height && events.mouse.y < (510.0/900.0)*desktop_height+50 )
                    { track02_can_play = true; G_STATE = Game; }
            }
            if( events.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP )
            {
                menu_current1 = menu_black;
                menu_current2 = menu_black;
            }

            if( track01_can_play )
            {
                al_stop_sample_instance( track02_instance );
                al_stop_sample_instance( track03_instance );
                al_play_sample_instance( track01_instance );
                track01_can_play = false;
            }
            al_draw_scaled_bitmap( map_pause, 0, 0, 1600, 900, 0, 0, desktop_width , desktop_height, 0 );
            al_draw_text( font2, menu_current1, (100.0/1600.0)*desktop_width, (400.0/900.0)*desktop_height, 0, "MAIN  MENU" );
            al_draw_text( font2, menu_current2, (100.0/1600.0)*desktop_width, (500.0/900.0)*desktop_height, 0, "BACK TO GAME" );
            al_flip_display();
        }
        else if( G_STATE == End ) //##########################################################END
        {
            if( events.type == ALLEGRO_EVENT_KEY_DOWN || events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN )
            { track01_can_play = true; G_STATE = Menu; }

            al_draw_scaled_bitmap( menu2_map, 0, 0, 1600, 900, 0, 0, desktop_width , desktop_height, 0 );

            switch( winner )
            {
                case 1: { al_draw_filled_rectangle( 0, 0, (100.0/1600.0)*desktop_width, desktop_height, al_map_rgb( 255, 0, 0 ) ); break; }
                case 2: { al_draw_filled_rectangle( 0, 0, (100.0/1600.0)*desktop_width, desktop_height, al_map_rgb( 51, 255, 0 ) ); break; }
                case 3: { al_draw_filled_rectangle( 0, 0, (100.0/1600.0)*desktop_width, desktop_height, al_map_rgb( 255, 255, 0 ) ); break; }
                case 4: { al_draw_filled_rectangle( 0, 0, (100.0/1600.0)*desktop_width, desktop_height, al_map_rgb( 0, 26, 153 ) ); break; }
            }
            al_flip_display();
        }
    }

    al_destroy_display( main_display );
    al_destroy_bitmap( game_map );
    al_destroy_bitmap( game_map2 );
    al_destroy_bitmap( menu1_map );
    al_destroy_bitmap( menu2_map );
    al_destroy_bitmap( map_infoboard_2 );
    al_destroy_bitmap( map_infoboard_3 );
    al_destroy_bitmap( map_infoboard_4 );
    al_destroy_bitmap( map_tut1 );
    al_destroy_bitmap( map_tut2 );
    al_destroy_bitmap( map_tut3 );
    al_destroy_bitmap( map_tut4 );
    al_destroy_bitmap( map_tut5 );
    al_destroy_bitmap( map_tut6 );
    al_destroy_bitmap( map_pause );
    al_destroy_bitmap( cursor_map );
    al_destroy_font( font1 );
    al_destroy_font( font2 );
    al_destroy_font( font3 );
    al_destroy_font( font4 );
    al_destroy_sample( sf_dice_toss );
    al_destroy_sample( sf_moving );track01_can_play = true;
    al_destroy_sample( sf_denied );
    al_destroy_sample( track01 );
    al_destroy_sample( track02 );
    al_destroy_sample( track03 );
    al_destroy_sample_instance( track01_instance );
    al_destroy_sample_instance( track02_instance );
    al_destroy_sample_instance( track03_instance );
    al_destroy_event_queue( event_q1 );
    al_destroy_timer( timer1 );

    return 0;
}
