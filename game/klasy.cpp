#include "klasy.hpp"

PIONEK::PIONEK( int nr )
{
    nr_pionka = nr;
    pole = 0;
    load_position_data_x( nr_pionka );
    load_position_data_y( nr_pionka );
}

void PIONEK::load_position_data_x( int nr )
{
    switch( nr )
    {
     case 1:
     case 3: file1.open( "pionek13x.txt", std::ios::in ); break;
     case 2:
     case 4: file1.open( "pionek24x.txt", std::ios::in ); break;
    }

    for( short i = 0; i < 40; i++ )
        file1 >> x[ i ];

    file1.close();
}

void PIONEK::load_position_data_y( int nr )
{
    switch( nr )
    {
    case 1:
    case 2: file1.open( "pionek12y.txt", std::ios::in ); break;
    case 3:
    case 4: file1.open( "pionek34y.txt", std::ios::in ); break;
    }

    for( short i = 0; i < 40; i++ )
        file1 >> y[ i ];

    file1.close();
}

float PIONEK::get_position_x( int p ) { return x[ p ]; }
float PIONEK::get_position_y( int p ) { return y[ p ]; }
void PIONEK::set_player_position( int position ) { pole = position; }

bool PIONEK::move_player( int &rv )
{
    bool flag = false;

    if( pole + rv < 40 ) { pole += rv; flag = true; }
    if( pole == 7 ) pole = 0;
    if( pole == 11 ) pole -= 1;
    if( pole == 13 ) pole = 6;
    if( pole == 15 ) pole += 2;
    if( pole == 18 ) pole = 23;
    if( pole == 19 ) pole += 1;
    if( pole == 25 ) pole += 1;
    if( pole == 30 ) pole = 35;
    if( pole == 31 ) pole -= 2;
    if( pole == 36 ) pole -= 3;

    if( flag ) return true;
    else return false;
}

void PIONEK::draw_checker( float &w, float &h )
{
    switch( nr_pionka )
    {
    case 1: { al_draw_filled_circle( ( x[ pole ]/1600.0 )*w, ( y[ pole ]/900.0 )*h, 12, al_map_rgb( 255, 0, 0 ) ); break; }
    case 2: { al_draw_filled_circle( ( x[ pole ]/1600.0 )*w, ( y[ pole ]/900.0 )*h, 12, al_map_rgb( 51, 255, 0 ) ); break; }
    case 3: { al_draw_filled_circle( ( x[ pole ]/1600.0 )*w, ( y[ pole ]/900.0 )*h, 12, al_map_rgb( 255, 255, 0 ) ); break; }
    case 4: { al_draw_filled_circle( ( x[ pole ]/1600.0 )*w, ( y[ pole ]/900.0 )*h, 12, al_map_rgb( 0, 26, 153 ) ); break; }
    }
}

void PIONEK::draw_position( const ALLEGRO_FONT *font3, float &dw, float &dh )
{
    if( nr_pionka == 1 )
    {
        std::string position_converted;
        position_converted = to_string( pole );
        al_draw_text( font3, al_map_rgb( 0, 0, 0 ), (1480.0/1600.0)*dw, (555.0/900.0)*dh, 0, position_converted.c_str() );
    }
    else if( nr_pionka == 2 )
    {
        std::string position_converted;
        position_converted = to_string( pole );
        al_draw_text( font3, al_map_rgb( 0, 0, 0 ), (1480.0/1600.0)*dw, (605.0/900.0)*dh, 0, position_converted.c_str() );
    }
    else if( nr_pionka == 3 )
    {
        std::string position_converted;
        position_converted = to_string( pole );
        al_draw_text( font3, al_map_rgb( 0, 0, 0 ), (1480.0/1600.0)*dw, (655.0/900.0)*dh, 0, position_converted.c_str() );
    }
    else if( nr_pionka == 4 )
    {
        std::string position_converted;
        position_converted = to_string( pole );
        al_draw_text( font3, al_map_rgb( 0, 0, 0 ), (1480.0/1600.0)*dw, (705.0/900.0)*dh, 0, position_converted.c_str() );
    }
}

bool PIONEK::check_finished_game()
{
    if( pole == 39 ) return true;
    else return false;
}

template< typename T >
std::string to_string( const T & obj )
{
    std::stringstream ss;
    ss << obj;
    return ss.str();
}

/*void player_moving_procedure( int cc, int nop )
{
    if( nop == 2 )
    {
        if( cc == 1 ) { p1.dice_toss(); cc++; }
        else if( cc == 2 ) { p2.dice_toss(); cc--; }
    }
    else if( nop == 3 )
    {
        if( cc == 1 ) { p1.dice_toss(); cc++; }
        else if( cc == 2 ) { p2.dice_toss(); cc++; }
        else if( cc == 3 ) { p3.dice_toss(); cc = 1; }
    }
    else if( nop == 4 )
    {
        if( cc == 1 ) { p1.dice_toss(); cc++; }
        else if( cc == 2 ) { p2.dice_toss(); cc++; }
        else if( cc == 3 ) { p3.dice_toss(); cc++; }
        else if( cc == 4 ) { p4.dice_toss(); cc = 1; }
    }
}
*/
