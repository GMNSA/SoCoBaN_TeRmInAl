#define EMPTY_DEFAULT 			' '
#define BOX_DEFAULT 			'*'
#define BOX_PLACE_DEFAULT		'.'
#define BOX_ON_PLACE_DEFAULT	'&'
#define PLAYER_DEFAULT			'@'

unsigned char x_1_1				= 9;
unsigned char y_1_1				= 9;
unsigned char box_on_places_1	= 6;
char *socoban_level_1[] = 
{
      "  XXXXX",
      " XX @ XX",
      "XX  *  XX",
      "X *...  X",
      "X  * *  X",
      "X  ...* X",
      "XX  *  XX",
      " XX   XX",
      "  XXXXX"
};

unsigned char x_1_2				= 9;
unsigned char y_1_2				= 9;
unsigned char box_on_places_2	= 8;
char *socoban_level_2[] = 
{
      "  XXXXX",
      " XX @ XX",
      "XX  ** XX"
      "X *...  X"
      "X .***. X"
      "X  ...* X"
      "XX  *  XX"
      " XX   XX"
      "  XXXXX"
};

unsigned char x_1_3				= 22;
unsigned char y_1_3				= 11;
unsigned char box_on_places_3	= 6;
char *socoban_level_3[] = 
{
	"    XXXXX",
	"    X   X",
	"    X*  X",
	"  XXX  *XXX",
	"  X  *  * X",
	"XXX X XXX X     XXXXXX",
	"XXX X XXX XXXXXXX  ..X",
	"X *  *             ..X",
	"XXXXX XXX X@XXXXX  ..X",
	"    X     XXX  XXXXXXX",
	"    XXXXXXX           ",
};

unsigned char x_1_4				= 11;
unsigned char y_1_4				= 9;
unsigned char box_on_places_4	= 10;
char *socoban_level_4[] = 
{
      "   XXXXX",
      "  XX @ XX",
      "XXX * * XXX",
      "X .*. .*. X",
      "X *.   .* X",
      "X .*. .*. X",
      "XXX * * XXX",
      "  XX   XX",
      "   XXXXX"
};
