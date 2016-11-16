#ifndef klasy_hpp
#define klasy_hpp

#include <allegro5\allegro.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>

enum GAME_STATE { Menu, About, Tutorial, Players, Game, Pause, End };

class PIONEK
{
private:
    int nr_pionka;
    int pole;
    float current_x;
    float current_y;
    float x[ 40 ];
    float y[ 40 ];
    std::fstream file1;

public:
    PIONEK( int nr );
    void load_position_data_x( int nr );
    void load_position_data_y( int nr );
    float get_position_x( int p );
    float get_position_y( int p );
    void set_player_position( int position );
    void draw_checker( float &w, float &h );
    bool move_player( int &rv );
    void draw_position( const ALLEGRO_FONT *font3, float &dw, float &dh );
    bool check_finished_game();
};

template< typename T >
std::string to_string( const T & obj );

#endif
