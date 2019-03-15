typedef struct //z_DemoCameraPointEntry, size 0x10
{
    /* 0x00 */ u8  lastRecord;  //0 if more entries, 0xFF if final entry
	
    //The following variables are ignored in camera position commands
    /* 0x01 */ s8  roll;
    /* 0x02 */ s16 frames;      //frames to next point, 0 if position list entry
    /* 0x04 */ f32 angleOfView; //Degrees
	
    //the following are used by both positions and focus points
    /* 0x08 */ Coord_s16 position;
    /* 0x0E */ u16 unknown;     //
} z_DemoCameraPointEntry;

typedef struct //z_DemoActionEntry, size 0x30
{
	/* 0x00 */ s16 action;
	/* 0x02 */ s16 startFrame;
	/* 0x04 */ s16 endFrame;
	/* 0x06 */ s16 unk_0x06;
	
	/* 0x08 */ s16 unk_0x08;
	/* 0x0A */ s16 unk_0x0A;
	/* 0x0C */ Coord_f32 pathStart;
	/* 0x18 */ Coord_f32 pathEnd;
	/* 0x24 */ vector3_f32 vertexNormal;
	
} z_DemoActionEntry;