/*
 * file:     br_codein.c
 * unit:     yes
 * function: func_021DB2E0, func_021DB36C, func_021DB394, func_021DB3C4, func_021DB594, func_021DB61C, func_021DB690, func_021DB698, func_021DB740, func_021DB770, func_021DB924, func_021DB940, func_021DBB3C, func_021DBBC4, func_021DBC68, func_021DBCA8, func_021DBCF4, func_021DBD40, func_021DBD7C, func_021DBEB0, func_021DBFB0, func_021DC228, func_021DC4FC, func_021DC638, func_021DC8EC, func_021DCBD8, func_021DCDD8, func_021DCE28, func_021DCE48, func_021DCEE4, func_021DD054, func_021DD0AC, func_021DD0F4, func_021DD128, func_021DD1D4, func_021DD228, func_021DD25C, func_021DD27C, func_021DD2BC, func_021DD2FC, func_021DD33C, func_021DD37C, func_021DD3F8, func_021DD440, func_021DD5C8, func_021DD684, func_021DD858, func_021DDA2C, func_021DDCCC, func_021DDDE8, func_021DDE2C, func_021DDF5C, func_021DDFA0, func_021DE000, func_021DE02C, func_021DE058, func_021DE084, func_021DE12C, func_021DE15C, func_021DE1C8, func_021DE234, func_021DE274, func_021DE3E4, func_021DE404, func_021DE55C, func_021DE66C, func_021DE780, func_021DE7C0, func_021DE8FC, func_021DE940, func_021DE9A0, func_021DEA30, func_021DEADC, func_021DEB4C, func_021DECB0, func_021DED14, func_021DED64, func_021DEDB4, func_021DEE7C, func_021DF0DC, func_021DF18C, func_021DF1DC, func_021DF388, func_021DF3DC, func_021DF41C, func_021DF428, func_021DF5B8, func_021DF620, func_021DF838, func_021DF8F0, func_021DF920, func_021DF9C8, func_021DFA10, func_021DFB90, func_021DFC88, func_021DFCD4, func_021DFE98, func_021DFF78, func_021DFFB0, func_021E0044, func_021E0080, func_021E009C, func_021E00D8, func_021E0214, func_021E024C, func_021E02F8, func_021E037C, func_021E03B0, func_021E04C8, func_021E050C, func_021E05C4, func_021E0618, func_021E06D0, func_021E0754, func_021E075C, func_021E0764, func_021E0774, func_021E07A4, func_021E0808, func_021E083C, func_021E0840, func_021E08E4, func_021E0954, func_021E0A88, func_021E0C04, func_021E0CE8, func_021E0D00, func_021E0D38, func_021E0D90, func_021E0E40, func_021E0E4C, func_021E0E90, func_021E1008, func_021E10A0, func_021E10BC, func_021E10DC, func_021E10F4, func_021E111C, func_021E11D0, func_021E1244, func_021E1374, func_021E138C, func_021E13D8, func_021E13FC, func_021E16E4, func_021E1708, func_021E1850, func_021E1910, func_021E19EC, func_021E1BA8, func_021E1C00, func_021E1C14, func_021E1C44, func_021E1C80, func_021E1D10, func_021E1D48, func_021E1DA8, func_021E1DF0, func_021E1E3C, func_021E2028, func_021E20A4, func_021E20F8, func_021E214C, func_021E2194, func_021E21E0, func_021E23C8, func_021E24AC, func_021E24C4, func_021E24F8, func_021E2538, func_021E2578, func_021E25E4, func_021E2640, func_021E26B8, func_021E2910, func_021E2AE0, func_021E2C2C, func_021E2E30, func_021E2E48, func_021E2E60, func_021E2E70, func_021E2F54
 * address:  0x021DB2E0
 * region:   ov183
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F9B9C 0x021F9B9C thumb ov186
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0201C440 0x0201C440 thumb
 *   func_021FD760 0x021FD760 thumb ov186
 *   func_021FD940 0x021FD940 thumb ov186
 *   func_021FD6D8 0x021FD6D8 thumb ov186
 *   func_021FD820 0x021FD820 thumb ov186
 *   func_021FD714 0x021FD714 thumb ov186
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_020315D4 0x020315D4 arm
 *   func_021FD71C 0x021FD71C thumb ov186
 *   func_021FD854 0x021FD854 thumb ov186
 *   func_021FD72C 0x021FD72C thumb ov186
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_021FD938 0x021FD938 thumb ov186
 *   func_021FC6A4 0x021FC6A4 thumb ov186
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021FC754 0x021FC754 thumb ov186
 *   func_021FE794 0x021FE794 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021FC734 0x021FC734 thumb ov186
 *   func_021FEE24 0x021FEE24 thumb ov186
 *   func_021F9BF4 0x021F9BF4 thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021FC830 0x021FC830 thumb ov186
 *   func_020061E4 0x020061E4 thumb
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   func_020409B4 0x020409B4 arm
 *   func_021FEE74 0x021FEE74 thumb ov186
 *   func_021F9BA0 0x021F9BA0 thumb ov186
 *   func_021FEE9C 0x021FEE9C thumb ov186
 *   func_021FEE4C 0x021FEE4C thumb ov186
 *   func_021FD744 0x021FD744 thumb ov186
 *   func_021FC1F8 0x021FC1F8 thumb ov186
 *   func_021FC148 0x021FC148 thumb ov186
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_021F9CB8 0x021F9CB8 thumb ov186
 *   func_021FE840 0x021FE840 thumb ov186
 *   func_021FBDA4 0x021FBDA4 thumb ov186
 *   func_021F9F48 0x021F9F48 thumb ov186
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FA018 0x021FA018 thumb ov186
 *   func_021F9FE8 0x021F9FE8 thumb ov186
 *   func_021FA004 0x021FA004 thumb ov186
 *   func_021FA01C 0x021FA01C thumb ov186
 *   func_021FC238 0x021FC238 thumb ov186
 *   func_021FC230 0x021FC230 thumb ov186
 *   func_021FC224 0x021FC224 thumb ov186
 *   func_021FE7F4 0x021FE7F4 thumb ov186
 *   func_02035D20 0x02035D20 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_02030EAC 0x02030EAC arm
 *   _u32_div_f 0x0209C2B0 arm
 *   d_021E3280 0x021E3280 data a4
 *   func_021FC240  0x021FC240  thumb  ov186
 *   BMP_OAM_CreateSys 0x02025538 thumb
 *   BATTLE_REC_GetHeader 0x0200B928 thumb
 *   BATTLE_REC_GetWork 0x0200B910 thumb
 *   BATTLE_REC_GetHeaderParam 0x0200B98C thumb
 *   func_021FD15C 0x021FD15C thumb ov186
 *   BMP_OAM_DeleteSys 0x02025588 thumb
 *   GAME_DATA_IsSaving 0x02012E40 thumb
 *   func_021FF88C 0x021FF88C thumb ov186
 *   func_021F9C6C 0x021F9C6C thumb ov186
 *   func_021FD6B0 0x021FD6B0 thumb ov186
 *   func_021FD1BC 0x021FD1BC thumb ov186
 *   func_021FB4B4 0x021FB4B4 thumb ov186
 *   func_021F9C50 0x021F9C50 thumb ov186
 *   func_021FD170 0x021FD170 thumb ov186
 *   func_021FF54C 0x021FF54C thumb ov186
 *   func_021FF648 0x021FF648 thumb ov186
 *   func_021FF72C 0x021FF72C thumb ov186
 *   func_021FF698 0x021FF698 thumb ov186
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   BATTLE_REC_SetData 0x0200B938 thumb
 *   GFL_USE_IsSeqPlaying 0x02006254 thumb
 *   func_021D7630 0x021D7630 thumb ov125
 *   d_021E3960 0x021E3960 data a1
 *   func_02034714 0x02034714 arm
 *   BATTLE_REC_DecodeWork 0x0200B490 thumb
 *   GAME_DATA_SaveStart 0x02012DAC thumb
 *   GAME_DATA_SaveMain 0x02012DD0 thumb
 *   func_021FC21C 0x021FC21C thumb ov186
 *   func_021FC868 0x021FC868 thumb ov186
 *   func_021FC7C4 0x021FC7C4 thumb ov186
 *   STRBUF_Create 0x020457B0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   func_02045EC0 0x02045EC0 arm
 *   GDS_PROFILE_CreateNameStr 0x0200D6D0 thumb
 *   func_0200D6EC 0x0200D6EC thumb
 *   func_0200D774 0x0200D774 thumb
 *   func_0201EE0C 0x0201EE0C thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   _ll_udiv 0x0209C00C arm
 *   _ull_mod 0x0209C018 arm
 *   d_021E32C8 0x021E32C8 data a4
 *   func_020490F4 0x020490F4 arm
 *   func_0201BC3C 0x0201BC3C thumb
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   func_0201BC40 0x0201BC40 thumb
 *   func_0201BCB4 0x0201BCB4 thumb
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   POKE_TOOL_CalcGraphicIndex 0x0201BABC thumb
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   func_0204B688 0x0204B688 arm
 *   func_0201BB5C 0x0201BB5C thumb
 *   func_0204B6F4 0x0204B6F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   d_021E32F0 0x021E32F0 data a2
 *   func_021FD1C4 0x021FD1C4 thumb ov186
 *   func_021FD640 0x021FD640 thumb ov186
 *   func_0204B3DC 0x0204B3DC arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   func_021FBE54 0x021FBE54 thumb ov186
 *   func_021FC124 0x021FC124 thumb ov186
 *   func_021FB378 0x021FB378 thumb ov186
 *   func_021FB494 0x021FB494 thumb ov186
 *   func_021FC0C8 0x021FC0C8 thumb ov186
 *   func_021FD12C 0x021FD12C thumb ov186
 *   d_021E32A8 0x021E32A8 data a4
 *   func_0200DABC 0x0200DABC thumb
 *   d_021E3350 0x021E3350 data a4
 *   func_0200DB44 0x0200DB44 thumb
 *   func_0200DAC4 0x0200DAC4 thumb
 *   func_0200DAD8 0x0200DAD8 thumb
 *   d_021E33C0 0x021E33C0 data a4
 *   d_021E3400 0x021E3400 data a4
 *   d_021E3490 0x021E3490 data a4
 *   func_0200DC08 0x0200DC08 thumb
 *   d_021E338C 0x021E338C data a4
 *   d_021E336C 0x021E336C data a4
 *   d_021E3440 0x021E3440 data a4
 *   func_0200DBA0 0x0200DBA0 thumb
 *   func_0201296C 0x0201296C thumb
 *   ZONEDATA_CheckEventFlag 0x020142E8 thumb
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   d_021E3358 0x021E3358 data a4
 *   BSUBWAY_SAVEDATA_GetStat 0x0200DFD8 thumb
 *   func_02012944 0x02012944 thumb
 *   func_0201F02C 0x0201F02C thumb
 *   d_021E3574 0x021E3574 data a4
 *   d_021E3664 0x021E3664 data a4
 *   d_021E35D4 0x021E35D4 data a4
 *   func_02045CAC 0x02045CAC arm
 *   d_021E351C 0x021E351C data a4
 *   d_021E3534 0x021E3534 data a4
 *   d_021E3964 0x021E3964 data a1
 *   func_021FF6DC 0x021FF6DC thumb ov186
 *   func_021FF704 0x021FF704 thumb ov186
 *   func_021FF6B4 0x021FF6B4 thumb ov186
 *   func_0201EC64 0x0201EC64 thumb
 *   BMP_MENUWORK_Create 0x0201F81C thumb
 *   func_021FC8C8 0x021FC8C8 thumb ov186
 *   BMP_Create 0x02043678 arm
 *   BMP_Clear 0x02043B5C arm
 *   STRBUF_SetString 0x02045924 arm
 *   func_0201D304 0x0201D304 thumb
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   func_021FCDAC 0x021FCDAC thumb ov186
 *   func_021FCE50 0x021FCE50 thumb ov186
 *   d_021E3700 0x021E3700 data a4
 *   func_021FCE0C 0x021FCE0C thumb ov186
 *   func_021FCDE8 0x021FCDE8 thumb ov186
 *   BMP_Delete 0x020437AC arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_021FCC80 0x021FCC80 thumb ov186
 *   BMP_MENUWORK_Delete 0x0201F868 thumb
 *   func_021FCD0C 0x021FCD0C thumb ov186
 *   func_021FCDA8 0x021FCDA8 thumb ov186
 *   func_0204B3F4 0x0204B3F4 arm
 *   CLACT_GetActorImageProxy 0x0204B7C8 arm
 *   func_0204B714 0x0204B714 arm
 *   CLACT_SetActorImageProxy 0x0204B784 arm
 *   func_02049E74 0x02049E74 arm
 *   CLACT_TransferCharacter 0x0204A9D0 arm
 *   CLACT_GetCharacterProxy 0x0204AB84 arm
 *   func_020307B0 0x020307B0 arm
 *   d_021E37A8 0x021E37A8 data a4
 *   d_021E3734 0x021E3734 data a2
 *   d_021E3740 0x021E3740 data a4
 *   func_0200856C 0x0200856C thumb
 *   func_02008570 0x02008570 thumb
 *   func_021FB4CC 0x021FB4CC thumb ov186
 *   BMP_MENUWORK_AddMsgItem 0x0201F878 thumb
 *   d_021E3758 0x021E3758 data a4
 *   d_021E3728 0x021E3728 data a4
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_021FFBD4 0x021FFBD4 thumb ov186
 *   func_021FFE5C 0x021FFE5C thumb ov186
 *   func_021FFE34 0x021FFE34 thumb ov186
 *   func_021FFE70 0x021FFE70 thumb ov186
 *   func_021FFC6C 0x021FFC6C thumb ov186
 *   func_021FFC9C 0x021FFC9C thumb ov186
 *   func_021FFE90 0x021FFE90 thumb ov186
 *   BMP_MENUWORK_AddStrItem 0x0201F898 thumb
 *   func_02025B64 0x02025B64 thumb
 *   func_0201F048 0x0201F048 thumb
 *   func_0201F094 0x0201F094 thumb
 *   d_021E3780 0x021E3780 data a4
 *   d_021E372E 0x021E372E data a4
 *   d_021E37D8 0x021E37D8 data ov183
 *   gSpeciesNameBank 0x020A7370 data a4
 *   g_021E3808     0x021E3808  data  ov183
 *   func_02030734 0x02030734 arm
 *   d_021E3968 0x021E3968 data ov183
 *   BUTTON_MAN_Delete 0x02051C6C arm
 *   d_021E3974 0x021E3974 data a4
 *   d_021E3978 0x021E3978 data ov183
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B404 0x0204B404 arm
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   CLACT_SetActorAnimFrame 0x0204B8C4 arm
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   BMP_OAM_Delete 0x0202570C thumb
 *   d_021E3850 0x021E3850 data a4
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   BMP_OAM_Create 0x020255A0 thumb
 *   BMP_OAM_UploadChars 0x020257D0 thumb
 *   BMP_OAM_SetObjMode 0x0202597C thumb
 *   d_021E3868 0x021E3868 data a4
 *   BUTTON_MAN_UpdateSlots 0x02051C88 arm
 *   CLACT_SetActorScale 0x0204B5AC arm
 *   d_021E3998 0x021E3998 data a4
 *   d_021E397C 0x021E397C data a4
 *   d_021E3858 0x021E3858 data a4
 *   STRBUF_Append 0x02045AA8 arm
 *   func_0201F35C 0x0201F35C thumb
 *   _ull_mul 0x0209C054 arm
 *   d_021E3880 0x021E3880 data a2
 *   BUTTON_MAN_Create 0x02051B84 arm
 *   d_021E38E0 0x021E38E0 data a4
 *   BATTLE_REC_Load 0x0200B570 thumb
 *   func_021FF67C 0x021FF67C thumb ov186
 *   func_021FD19C 0x021FD19C thumb ov186
 *   d_021E39B4 0x021E39B4 data a4
 *   func_021D76A8 0x021D76A8 thumb ov125
 *   func_021D76D8 0x021D76D8 thumb ov125
 *   d_021E3900 0x021E3900 data a4
 *   func_021E2F98 0x021E2F98 thumb ov183
 *   func_021E300C 0x021E300C thumb ov183
 *   func_021E31E8 0x021E31E8 thumb ov183
 *   func_021E3228 0x021E3228 thumb ov183
 *   func_021D7540 0x021D7540 thumb ov125
 *   d_021E3910 0x021E3910 data a4
 *   d_021E3928 0x021E3928 data a4
 */
#include "br_codein_types.h"
#include "soc_types.h"

struct Obj24810;
struct Obj0203159C;
struct S020315D4;
struct PrintSys;
struct Obj;
struct Node;
struct ObjC4;
struct Big;
struct Actor;
struct Blk1AC;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct BigObj;
struct Bmp;
struct CharBuf;
struct State;
struct StrObj;
struct Strbuf;
struct Obj020437AC;
struct Struct36;
struct Sub0204A9D0;
struct Sub0200852CObj;
struct Object;
struct Coordinates;
struct Vec2;
struct PtS;
struct Grid;
struct Sys;
struct Param;
struct Ctx;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long long u64;
typedef signed short s16;

typedef struct {char pad[0x4c];char saved[0x18];int count;void *ptr;} S_021DB2E0;

typedef struct S_021DBFB0 S_021DBFB0;

typedef struct S S;

typedef struct {u8 x,y,w,h;u32 message;} Descriptor_021DB2E0;

typedef struct U16Vec U16Vec;

typedef struct MsgBank MsgBank;

typedef struct WordSet WordSet;

typedef struct GdsProfile GdsProfile;

typedef struct GdsRecord GdsRecord;

typedef struct RecGet RecGet;

typedef struct {s16 x,y,z;u8 a,b;} Position;

typedef struct {s16 x,y;} Point16;

typedef signed int     s32;


typedef struct Triple { int a,b,c; } Triple;



typedef struct Point { u32 x,y; } Point;





typedef struct Rect { u32 x0, y0, x1, y1; } Rect;




typedef u16 Row[3];




struct Data_021DB2E0 { u8 pad[0x1718]; int count; u32 selected; };

typedef struct {void *text;int id;} Item;

typedef struct {Item *list;u32 count;u8 x,y,width,height,palette,bg,spacing,pad;int mode;char *resources;u32 manager,cursor,other;u16 *selection;} Config_021DF1DC;

typedef struct {u32 words[10];} CfgTpl;

typedef struct Slot_021DB2E0 { u32 a,b; } Slot_021DB2E0;

typedef struct {Slot_021DB2E0 *list;void *view;void *words;u32 c,d;u8 pad[0xbc];char *base;} Menu;

typedef signed char s8;

struct State_021DF428 { u8 pad[0x14]; u16 shared0,shared1; u16 indices[5][6]; int cursor; void *sprites[5][6]; char *source; };

struct Pos { u16 x; short y; u16 z; u8 a,b; };

struct Entries { u32 species[6],form[6],gender[6]; };

struct W { char pad[0x18]; u16 handles[5][6]; char gap[4]; void *objects[5][6]; };

struct Rec { u32 w[9]; };

struct Sub { u8 pad[16]; u32 size,data; };

typedef int (*Method)(char *,int *);

struct Methods { Method init,update,finish; };


typedef struct Rec6 { u8 x,y,id,pad; u16 file; } Rec6;

struct Rec8 { u8 a,b,c,d; void *value; };


typedef struct {u16 a,b,c;u8 flag,pad;} Params;



typedef struct Record { u8 a, b, c, d; int value; } Record;


struct Data_021DF388 { void *a, *b, *c, *d; u16 heap; u16 pad; void *e; };


struct Object { int capacity; int entries[4]; int unused; void *vector; void *a; void *b; void *c; };

struct PosParams {s16 x,y,a,b,z;u8 mode,flag;};

struct Coordinates { u8 pad[0x298]; u8 rect[32][4]; };

typedef struct {s16 a,b,x,y;} Coords;

typedef struct {void *handle; short x,y; unsigned data,zero; u8 a,b; u16 c; unsigned d;} Descriptor_021E111C;

typedef struct {char f000[0x300]; struct Sys *f300; struct Grid *f304[1];} Object;

typedef enum {INDEX_0,INDEX_1} Index;

typedef struct 
{
  int v[3];
} Row_021E1244;

typedef struct 
{
  Row_021E1244 row[2];
} Table_021E1244;

typedef struct 
{
  char pad[0x328];
  int count;
} State_021E111C;



typedef struct {int tag,value,mode,handle; char rest[12];} Record_021E111C;

typedef struct {short a,b,c,d;} Row_021E1910;

typedef struct {Row_021E1910 row[12];} Table_021E1910;



typedef struct { u32 index; u8 f4[8]; char *owner; u8 f10[8]; u32 base; } Input;

typedef struct { u8 a,b,c,d; void *value; } Rec;

typedef signed long long s64;

typedef enum { STATE_ZERO=0, STATE_TWELVE=12 } State_021E21E0;


typedef struct {u32 fields[7];Point request;} Arg;





typedef union Config_021E111C {u64 wide;Point pair;} Config_021E111C;



typedef struct Table {int head[4];SOCLResource pair;} Table;

extern unsigned func_021F9B9C(struct Obj24810 *p);
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void * func_02082BCC(void *,int,unsigned);
extern u32 func_0201C440(void *p);
extern char *func_021FD760(unsigned owner, char *resources, int index, int heap);
extern void func_021FD940(u8 *p, u32 value);
extern int *func_021FD6D8(int payload, int callback, u32 heap);
extern void func_021FD820(char *);
extern void func_021FD714(void *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_020315D4(struct S020315D4 *);
extern void func_021FD71C(u8 *p);
extern void func_021FD854(char *);
extern int func_021FD72C(int *);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *);
extern void func_021FD860(void *, unsigned, const Point *);
extern int func_021FD938(char *);
extern void *func_021FC6A4(unsigned short,unsigned,unsigned short,unsigned short,unsigned char,unsigned char,void *,unsigned short);
extern unsigned func_021FC20C(char *p);
extern int func_021FC214(char *);
extern void func_021FC754(char *,void *,void *,void *,unsigned short);
extern void func_021FE794(char *p, u32 index, u32 a, u32 b, u32 c);
extern int func_021FE7B0(int *);
extern void func_021FC734(u8 *p);
extern void func_021FEE24(char *p);
extern int func_021FC830(u8 *p);
extern void func_021F9BF4(unsigned *,unsigned);
extern int *func_021FD73C(int *p, int v);
extern void func_020061E4(u32 a);
extern void func_020409B4(u32 index);
extern int TOUCHPANEL_GetTrg(void);
extern void func_021FEE74(char *p);
extern void func_021F9BA0(unsigned *ctx);
extern void func_021FEE9C(char *p);
extern void func_021FEE4C(char *p);
extern int func_021FD744(int *a);
extern void func_021FC1F8(int *,int);
extern void func_021FC148(char *p, unsigned i, unsigned heap);
extern void func_021FB964(void *ctx, unsigned kind, unsigned short heap);
extern struct Obj *func_021F9CB8(int a, int b, int c, int d, int e, int f, u32 heap);
extern void func_021FE840(int,int,int);
extern void func_021FE784(int,int,int,int);
extern int func_021FA018(char *),func_021FA01C(char *);
extern void func_021F9FE8(char *);
extern int func_021FA004(char *,int *,int *);
extern int func_021FC238(char *),func_021FC224(char *);
extern void func_021FC230(char *,int),func_021FE7F4(int *,int);
extern u32 func_02035D20(u32 *,u32 *);
extern void *func_020056A0(void (*)(void),void *,int);
extern void func_02030EAC(struct Node *n);
extern void func_021FC240(char *p, void *owner, unsigned short heap);
extern void * BMP_OAM_CreateSys(unsigned,void *);
extern char * BATTLE_REC_GetHeader(void);
extern struct ObjC4 *BATTLE_REC_GetWork(void);
extern unsigned long long BATTLE_REC_GetHeaderParam(u8 *p, int selector, int index);
extern void func_021FD15C(void *,int);
extern void BMP_OAM_DeleteSys(void *p);
extern u8 GAME_DATA_IsSaving(const u8 *o);
extern int func_021FF88C(char *p);
extern void func_021F9C6C(void *);
extern int func_021FD6B0(u8 *p);
extern void func_021FD1BC(void *);
extern int func_021FB4B4(unsigned int *obj, int x, int y);
extern void func_021F9C50(S_021DB2E0 *);
extern void func_021FD170(char *p, char *q, void *text);
extern void func_021FF54C(char *p, int kind, const int *values);
extern int func_021FF648(char *p);
extern int func_021FF72C(char *p, int *out);
extern int func_021FF698(char *,int,int *);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void BATTLE_REC_SetData(const void *,const void *,const void *,unsigned int);
extern int GFL_USE_IsSeqPlaying(u32 a);
extern int func_021D7630(void *a, int x, u16 *state, u16 *b, u16 c);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void BATTLE_REC_DecodeWork(void);
extern int GAME_DATA_SaveStart(int),GAME_DATA_SaveMain(u8 *);
extern int func_021FC21C(char *);
extern void func_021FC868(u8 *p, u32 a, u32 b, u32 c);
extern void func_021FC7C4(char *,void *,void *,u16);
extern struct U16Vec *STRBUF_Create(u32 capacity, u16 heapId);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *GDS_PROFILE_CreateNameStr(const void *,u32);
extern void *func_0200D774(struct GdsProfile *p, struct GdsRecord *out, u32 tag);
extern u32 func_0200D6EC(struct RecGet *p);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void *func_020490F4(u32 id, u32 heap);
extern int func_0201BC3C(void),func_0201BC40(void),func_0201BCB4(void);
extern int CLACT_RegisterPaletteCompressed(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern u32 POKE_TOOL_CalcGraphicIndex(u32,u32,u32,u32),func_0201BB5C(u32,u32,u32,u32);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern struct Obj *CLACT_CreateActor(void *owner, u32 i, u32 j, u32 k, const void *position, u16 f, u16 g);
extern void func_0204B688(struct Actor *actor, u32 value);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void ARC_TOOL_DeleteHandle(void *);
extern char *func_021FD1C4(void *prof, char *q, void *a2, void *a3, int mode, u16 heap);
extern void func_021FD640(int *);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern void func_021FBDA4(int a, unsigned mode);
extern void func_021FBE54(char *,u32,u32);
extern int func_021FC124(void *,int,Triple *);
extern void *func_021FB378(void *,int,int,int,int,int,int,int,void *,u16);
extern void func_021FB494(char *p);
extern void func_021FC0C8(char *p, unsigned i);
extern void *func_021FD12C(int a, void *owner, u16 heap);
extern u16 func_0200DABC(struct Blk1AC *p);
extern u32 func_0200DB44(struct Blk1AC *p, u32 i);
extern u16 func_0200DAC4(struct Blk1AC *p, u32 i);
extern u16 func_0200DAD8(struct Blk1AC *p, u32 i);
extern u8 func_0200DC08(struct Blk1AC *p);
extern u32 func_0200DBA0(struct Blk1AC *p, s32 i, u32 op);
extern u32 func_0201296C(const struct BigObj *p);
extern u32 ZONEDATA_CheckEventFlag(void *,int);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern u16 BSUBWAY_SAVEDATA_GetStat(Row *,int,int);
extern u8 *func_02012944(void *p);
extern void func_0201F02C(struct WordSet *,u32,void *);
extern void func_02045CAC(struct MsgBank *,u32,void *);
extern int func_021FF6DC(char *p, void *buffer, int count, int *out);
extern int func_021FF704(char *p, void *buffer, int count, int *out);
extern int func_021FF6B4(char *p, void *buffer, int count, int *out);
extern struct WordSet *func_0201EC64(u32 heap);
extern Slot_021DB2E0 *BMP_MENUWORK_Create(u32,u32);
extern void *func_021FC8C8(const Config_021DF1DC *,u16);
extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void STRBUF_SetString(struct Strbuf *o, const u16 *src);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void PRINTSYS_PrintColor(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern void func_021FCDAC(u8 *p, u16 i, u32 v);
extern void func_021FCE50(char *p);
extern int func_021FCE0C(char *p, unsigned field);
extern u32 func_021FCDE8(u8 *p, u16 i);
extern void BMP_Delete(struct Obj020437AC *p);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_021FCC80(char *p);
extern u32 BMP_MENUWORK_Delete(void *p);
extern void func_021FCD0C(char *p);
extern int func_021FCDA8(char *);
extern int func_0201BC3C(void);
extern int func_0201BC40(void);
extern u32 func_0204B3F4(struct Obj *p);
extern u32 func_0204B714(struct Obj *o);
extern void CLACT_GetActorImageProxy(const char *src, struct Struct36 *dst);
extern void CLACT_SetActorImageProxy(char *dst, const struct Struct36 *src);
extern void *func_02049E74(void *,u32,u32,u32,u16);
extern void CLACT_TransferCharacter(int a, struct Sub0204A9D0 *b);
extern void CLACT_GetCharacterProxy(u32,struct Rec *);
extern u32 func_020307B0(void *p);
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern u8 func_02008570(const struct Sub0200852CObj *obj);
extern int func_021FB4CC(u32 *p, int a1, int a2);
extern void BMP_MENUWORK_AddMsgItem(Slot_021DB2E0 *table, u32 a, u32 b, u32 tag, u32 heap);
extern void *func_0200CA1C(void *);
extern char *func_021FFBD4(void *, void *, int, int, int, int, int, u16);
extern void func_021FFE5C(char *);
extern unsigned func_021FFE34(char *p);
extern void func_021FFE70(char *p);
extern void func_021FFC6C(char *p);
extern int func_021FFC9C(char *);
extern int func_021FFE90(int *, u16 *);
extern void BMP_MENUWORK_AddStrItem(Slot_021DB2E0 *table, u32 a, u32 b, u32 tag);
extern u8 func_02025B64(u32);
extern void func_0201F048(struct WordSet *p, u32 i, u32 n);
extern void func_0201F094(struct WordSet *p, u32 i, u32 a, u32 n);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void BUTTON_MAN_Delete(void *);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
extern void CLACT_SetActorAnimFrame(struct Obj *p, u32 value);
extern u16 CLACT_GetActorAnimSeq(struct Obj *p);
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern void BMP_OAM_Delete(struct Grid *);
extern void PRINTSYS_Print(void *x, s16 y, s16 z, void *s, void *w);
extern struct Grid *BMP_OAM_Create(struct Sys *sys, const struct Param *param);
extern void BMP_OAM_UploadChars(struct Obj *o);
extern void BMP_OAM_SetObjMode(u8 *g, u32 a);
extern s32 BUTTON_MAN_UpdateSlots(struct Ctx *c);
extern void CLACT_SetActorScale(struct Obj *dst, Point *src);
extern void STRBUF_Append(struct U16Vec *dst, struct U16Vec *src);
extern void func_0201F35C(void *, int, u32, u32, u32);
extern void *BUTTON_MAN_Create(u8 *,int,int,int);
extern u32 BATTLE_REC_Load(void *a, u16 heap, u32 *dp, u32 id);
extern u32 func_021FF67C(u8 *p, unsigned long long *out);
extern void func_021FD19C(char *p, void *q, void *text);
extern void func_021D76A8(int,int,int);
extern int func_021D76D8(char *p, int id);
extern void func_021E2F98(SOCLResource *resource);
extern void func_021E300C(Point *);
extern int func_021E31E8(char *,int,int),func_021E3228(char *,int,int);
extern int func_021D7540(void *a, int x, int mode, u16 *state, u16 *b, u16 c);
int func_021DB2E0(int *task, int unused, char *p);
int func_021DB36C(struct S020315D4 *task,int b,int c,struct CodeinWorkB *p);
int func_021DB394(int a,int b,int c,struct CodeinWorkB *p);
void func_021DB3C4(int *task,int *state,struct CodeinWorkE *p);
void func_021DB594(int *task, int *state, struct CodeinWorkA *p);
void func_021DB61C(int *task, int *state, struct CodeinWorkA *p);
void func_021DB690(int *task);
int func_021DB698(int *task,int b,char *p);
int func_021DB740(struct S020315D4 *task,int b,struct CodeinArgB *q,struct CodeinWorkA *p);
int func_021DB770(int *task,int *state,struct CodeinWorkB *p,struct CodeinArgA *q);
void func_021DB924(int a0, struct CodeinWorkF *p);
int func_021DB940(int *task,int *state,char *q);
int func_021DBB3C(int task,int b,char *q,char *p);
int func_021DBBC4(int a,int b,int c,struct CodeinWorkB *p);
void func_021DBC68(int a, int b, char *p);
void func_021DBCA8(int *task, int *state, struct CodeinWorkA *p);
void func_021DBCF4(int *task, int *state, struct CodeinWorkA *p);
void func_021DBD40(int *task,int b,char *p);
void func_021DBD7C(int *task,int *state,char *p);
void func_021DBEB0(int *task,int *state,char *p);
void func_021DBFB0(int *a,int *state,char *p);
void func_021DC228(int *a,int *state,char *p);
void func_021DC4FC(int *a,int *state,char *p);
void func_021DC638(int *a,int *state,char *p);
void func_021DC8EC(char *p,char *q);
void func_021DCBD8(char *p,void *manager,void *party,u16 heap);
void func_021DCDD8(char *p, char *q);
void func_021DCE28(char *p,char *unused);
void func_021DCE48(char *p,char *q);
void func_021DCEE4(char *p,char *q);
void func_021DD054(char *p, char *q);
void func_021DD0AC(char *p, char *unused);
void func_021DD0F4(char *p, char *a1);
void func_021DD128(char *p, char *q);
void func_021DD1D4(char *p, char *q);
int func_021DD228(void *p);
int func_021DD25C(void *p);
int func_021DD27C(char *p, int a, int b);
int func_021DD2BC(char *p, int a, int b);
int func_021DD2FC(char *p, int a, int b);
int func_021DD33C(char *p, int a, int b);
int func_021DD37C(void *a, int unused, char *q);
int func_021DD3F8(struct S020315D4 *a, int unused, char *q, char *p);
int func_021DD440(void *unused,u32 *state,char *q,char *p);
void func_021DD5C8(struct CodeinWorkA *p, char *q);
void func_021DD684(char *p,char *q);
void func_021DD858(char *p,char *q);
void func_021DDA2C(char *p, char *q);
void func_021DDCCC(char *p,char *q);
void func_021DDDE8(char *p, char *q);
void func_021DDE2C(struct CodeinWorkA *p,char *q);
void func_021DDF5C(char *p, char *q);
int func_021DDFA0(char *p, int x, int y);
int func_021DE000(void *p,char *q);
int func_021DE02C(void *p, void *q);
int func_021DE058(void *p, void *q);
void func_021DE084(char *p, void *manager, const char *q, unsigned int value, s16 x, s16 y, u16 heap);
void func_021DE12C(char *p);
void func_021DE15C(char *p, u32 value);
int func_021DE1C8(void *a, int b, char *q);
int func_021DE234(void *a, int b, char *q, struct CodeinWorkA *p);
int func_021DE274(void *unused,u32 *state,char *q,struct CodeinWorkA *p);
void func_021DE3E4(char *p, char *q);
void func_021DE404(struct CodeinWorkA *p,char *q);
void func_021DE55C(struct CodeinWorkA *p,char *q);
void func_021DE66C(struct CodeinWorkA *p,char *q);
void func_021DE780(struct CodeinWorkA *p, char *q);
void func_021DE7C0(char *p,char *q);
void func_021DE8FC(struct CodeinWorkA *p, char *q);
int func_021DE940(struct CodeinWorkA *p, int x, int y);
int func_021DE9A0(void *a, int b, char *q);
int func_021DEA30(void *a, int b, struct CodeinArgA *q, struct CodeinWorkA *p);
int func_021DEADC(int a, int b, int c, struct CodeinWorkA *p);
void func_021DEB4C(int *task,int *state,struct CodeinWorkD *p);
void func_021DECB0(void *a, int b, struct CodeinWorkA *p);
void func_021DED14(int *a, int *state, struct CodeinWorkA *p);
void func_021DED64(int *p, int *state, struct CodeinArgA *q);
void func_021DEDB4(int *task, int *state, char *p);
void func_021DEE7C(int *task,u32 *state,char *p);
void func_021DF0DC(int *p, int *state, struct CodeinArgA *q);
void func_021DF18C(int *p, int *state, struct CodeinArgA *q);
void func_021DF1DC(Menu *p,char *base,char *res,u32 mgr,u32 a5,u32 a6,u16 *sel,u16 heap);
void func_021DF388(char *p);
void func_021DF3DC(char *p, u16 a);
int func_021DF41C(char *p);
void func_021DF428(struct State_021DF428 *p,u32 mgr,u16 heap);
void func_021DF5B8(char *p);
void func_021DF620(struct State_021DF428 *p,int first,short step,u16 heap);
void func_021DF838(int p, char *out);
int func_021DF8F0(int x, int y);
int func_021DF920(void *obj, int unused, struct CodeinArgB *q);
int func_021DF9C8(void *p, int unused, struct CodeinArgA *q, char *data);
int func_021DFA10(void *unused,u32 *state,int *q,char *p);
int func_021DFB90(struct CodeinWorkA *p,struct CodeinArgA *q);
int func_021DFC88(char *p, struct CodeinArgA *q);
int func_021DFCD4(struct CodeinWorkB *p,struct CodeinArgB *q);
int func_021DFE98(struct CodeinWorkB *p,struct CodeinArgA *q);
int func_021DFF78(struct CodeinWorkB *p, struct CodeinArgA *q);
int func_021DFFB0(struct CodeinWorkB *p, struct CodeinArgB *q);
void func_021E0044(struct CodeinWorkA *p, struct CodeinArgA *q);
int func_021E0080(struct CodeinWorkA *p);
int func_021E009C(struct CodeinWorkB *p, struct CodeinArgB *q);
int func_021E00D8(struct CodeinWorkB *p,struct CodeinArgA *q);
int func_021E0214(struct CodeinWorkB *p, struct CodeinArgA *q);
int func_021E024C(struct CodeinWorkB *p, struct CodeinArgB *q);
void func_021E02F8(struct CodeinWorkA *p, int *q);
void func_021E037C(char *p,struct CodeinArgA *q);
void func_021E03B0(struct CodeinWorkB *p,struct CodeinArgB *q,int mode);
int func_021E04C8(void);
int func_021E050C(void *task, int unused, struct CodeinArgA *q);
int func_021E05C4(void *a, int unused, int *q, void **p);
int func_021E0618(int unused, int *state, int *q, int *p);
char *func_021E06D0(const CfgTpl *src, u16 heap);
void func_021E0754(char *p);
int func_021E075C(char *p);
u64 func_021E0764(char *p);
void func_021E0774(struct CodeinWorkA *p);
struct Object *func_021E07A4(int heap, int n, void *a, void *b, void *c, int *entries);
void func_021E0808(struct CodeinWorkB *p);
void func_021E083C(void);
void func_021E0840(char *p);
void func_021E08E4(struct CodeinWorkA *p);
void func_021E0954(char *p);
void func_021E0A88(char *p);
void func_021E0C04(char *p);
void func_021E0CE8(char *p, int index, int a2);
void func_021E0D00(char *p,int i);
void func_021E0D38(struct Coordinates *p, int index);
void func_021E0D90(char *p);
int func_021E0E40(int a, int b);
void func_021E0E4C(char *p);
void func_021E0E90(char *p,int animated);
void func_021E1008(char *p);
void func_021E10A0(char *p);
void func_021E10BC(struct CodeinWorkA *p);
void func_021E10DC(char *p);
void func_021E10F4(char *p);
void func_021E111C(const Object *object,Index index,int x,int y,int unused);
void func_021E11D0(char *p,int state);
void func_021E1244(State_021E111C *p);
void func_021E1374(char *p, int v);
int func_021E138C(char *p);
int func_021E13D4(void);
s32 func_021E13D8(char *p);
int func_021E13FC(char *p);
int func_021E16E4(char *p);
void func_021E1708(char *p);
void func_021E1850(const Record_021E111C *records);
void func_021E1910(char *p);
void func_021E19EC(u32 idx, int arg, char *p);
void func_021E1BA8(char *p);
void func_021E1C00(char *p);
int func_021E1C14(char *p,int a);
int func_021E1C44(const char *p, int a);
int func_021E1C80(struct Obj0203159C *obj,int unused,char *arg);
int func_021E1D10(struct S020315D4 *a,int b,struct CodeinArgA *q,struct CodeinWorkA *p);
int func_021E1D48(int a,int b,int c,struct CodeinWorkB *p);
void func_021E1DA8(int a,int *state,struct CodeinWorkB *p);
void func_021E1DF0(int *a,int *state,struct CodeinWorkB *p);
void func_021E1E3C(int *task,int *state,struct CodeinWorkB *p);
int func_021E2028(struct Obj0203159C *obj,int unused,char *arg);
int func_021E20A4(int obj,int b,char *arg,char *p);
int func_021E20F8(int a,int b,int c,struct CodeinWorkA *p);
void func_021E214C(int *task,int *state,struct CodeinWorkA *p);
void func_021E2194(int *task,int *state,struct CodeinWorkA *p);
void func_021E21E0(int task,int *state,char *p);
void func_021E23C8(char *p,const Input *q);
void func_021E24AC(char *p, char *a1);
void func_021E24C4(char *p,char *q);
int func_021E24F8(char *p, int a, int b);
int func_021E2538(char *p, int a, int b);
int func_021E2578(void *obj,int b,char *q);
int func_021E25E4(int obj,int b,int c,char *p);
int func_021E2640(int a,int b,int c,struct CodeinWorkA *p);
void func_021E26B8(int *task,State_021E21E0 *state,char *p);
void func_021E2910(int *task,int *state,char *p);
void func_021E2AE0(int *task,unsigned *state,char *p);
void func_021E2C2C(int *task,unsigned *state,char *p);
void func_021E2E30(char *p, int a1, int a2);
void func_021E2E48(char *p,int a,int b);
void func_021E2E60(SOCLResource *p);
void func_021E2E70(char *p, const char *q);
void func_021E2F54(struct CodeinWorkA *p,struct CodeinArgA *q);
extern int d_021E3280[];
extern char d_021E3960[];
extern const Descriptor_021DB2E0 d_021E32C8[];
extern const Point16 d_021E32F0[];
extern const Record d_021E32A8[];
extern const Record d_021E3350[];
extern const Record d_021E33C0[];
extern const Record d_021E3400[];
extern const Record d_021E3490[];
extern const Record d_021E338C[];
extern const Record d_021E336C[];
extern const Rect d_021E3440[];
extern const u32 d_021E3358[];
extern const Record d_021E3574[];
extern const Record d_021E3664[];
extern const Record d_021E35D4[];
extern const Record d_021E351C[];
extern const Rect d_021E3534[];
extern const char d_021E3964[];
extern const CfgTpl d_021E3700;
extern const struct Methods d_021E37A8[];
extern const struct Rec6 d_021E3734[];
extern const struct Rec8 d_021E3740[];
extern const CfgTpl d_021E3758;
extern const Rec6 d_021E3728[];
extern const CfgTpl d_021E3780;
extern const Rec6 d_021E372E[];
extern const Record d_021E37D8[];
extern int gSpeciesNameBank;
extern Rect g_021E3808[];
extern char d_021E3968[];
extern char d_021E3974[];
extern char d_021E3978[];
extern const int d_021E3850[];
extern const Table_021E1244 d_021E3868;
extern const int d_021E3998[],d_021E397C[];
extern const Table_021E1910 d_021E3880;
extern const Point d_021E38E0;
extern char d_021E39B4[];
extern const Rec d_021E3900[];
extern const Table d_021E3910;
extern const unsigned char d_021E3928[];















int func_021DB2E0(int *task, int unused, char *p)
{
    struct CodeinStateA *s;
    void *callback;
    s=PROCSYS_AllocProcWork((struct Obj0203159C *)task,0x20,func_021F9B9C(((struct CodeinWorkA *)p)->f10));
    func_02082BCC(s,0,0x20);
    s->f1C=p;
    s->f4=func_021F9B9C(((struct CodeinWorkA *)p)->f10);
    s->fC=(void *)func_0201C440((void *)(s->f4));
    s->f14=func_021FD760((*(int *)&((struct CodeinWorkA *)p)->f4),(char *)((*(int *)&((struct CodeinWorkA *)p)->fC)),0,s->f4);
    s->f18=func_021FD760((*(int *)&((struct CodeinWorkA *)p)->f4),(char *)((*(int *)&((struct CodeinWorkA *)p)->fC)),1,s->f4);
    func_021FD940(s->f14,1);
    func_021FD940(s->f18,1);
    if((*(int *)&((struct CodeinWorkA *)p)->f0)==0) callback=func_021DB3C4;
    else if((*(int *)&((struct CodeinWorkA *)p)->f0)==1) callback=func_021DB594;
    else callback=func_021DB61C;
    s->f0=func_021FD6D8((int)s,(int)callback,s->f4);
    return 1;
}















int func_021DB36C(struct S020315D4 *task,int b,int c,struct CodeinWorkB *p) { func_021FD820(*(char * *)&p->f14); func_021FD820(*(char * *)&p->f18); func_0201C4C0((*(void * *)&p->fC)); func_021FD714((void *)(p->f0)); func_020315D4(task); return 1; }















int func_021DB394(int a,int b,int c,struct CodeinWorkB *p) { func_021FD71C((u8 *)(p->f0)); PRINTSYS_QUE_Main(*(struct PrintSys * *)&p->fC); func_021FD854(*(char * *)&p->f14); func_021FD854(*(char * *)&p->f18); if(func_021FD72C(*(int * *)&p->f0)) return 1; return 0; }















/*
 * lever: enum-valued one-bit mask preserves the original call/mask scheduling, as in sibling 021DB594.
 * abi: 02035C60 returns a full word consumed by the original caller's comparison.
 */
void func_021DB3C4(int *task,int *state,struct CodeinWorkE *p)
{
    int a,b;
    switch(*state) {
    case 0: {Point args;args.x=128;args.y=96;func_021FD860((void *)(p->f14), 2, &args);func_020061E4(0x700);*state=1;break;}
    case 1: if(func_021FD938(*(char * *)&p->f14))*state=2;break;
    case 2: {Point args;args.x=128;args.y=-8;func_021FD860((void *)(p->f18), 3, &args);*state=3;break;}
    case 3: if(func_021FD938(*(char * *)&p->f18))*state=4;break;
    case 4:
        p->f8=func_021FC6A4(4,8,16,16,2,14,p->fC,p->f4);
        a=func_021FC20C(*(char * *)&((struct CodeinSubA *)(p->f1C))->fC);
        b=func_021FC214(*(char * *)&((struct CodeinSubA *)(p->f1C))->fC);
        func_021FC754(*(char * *)&p->f8,(void *)b,(void *)228,(void *)a,0x440);
        func_021FE794((char *)((*(int *)&((struct CodeinSubA *)(p->f1C))->f8)),3,15,1,4);*state=5;break;
    case 5: if(func_021FE7B0(((struct CodeinSubA *)(p->f1C))->f8))*state=6;break;
    case 6: func_021FE794((char *)((*(int *)&((struct CodeinSubA *)(p->f1C))->f8)),3,15,0,4);*state=7;break;
    case 7: if(func_021FE7B0(((struct CodeinSubA *)(p->f1C))->f8))*state=8;break;
    case 8: if(TOUCHPANEL_GetTrg()) {func_020061E4(0x6ff);func_021FC734(p->f8);*(int *)&p->f8=0;func_020409B4(4);*state=9;}break;
    case 9: func_021FE794((char *)((*(int *)&((struct CodeinSubA *)(p->f1C))->f8)),3,3,0,48);func_021FEE24((char *)(((struct CodeinSubA *)(p->f1C))->f14));*state=10;break;
    case 10: {enum {ONE=1} mask=ONE;if(func_021FE7B0((int *)(((struct CodeinSubA *)(p->f1C))->f8))&mask) {func_021FD860((void *)(p->f18), 8, 0);*state=11;}break;}
    case 11: func_021FE794((char *)((*(int *)&((struct CodeinSubA *)(p->f1C))->f8)),2,3,1,1);*state=12;break;
    case 12: if(func_021FE7B0(((struct CodeinSubA *)(p->f1C))->f8))*state=13;break;
    case 13: if(func_021FD938(*(char * *)&p->f18)) {func_021F9BF4(*(unsigned * *)&((struct CodeinSubA *)(p->f1C))->f10,1);func_021FD73C(task,(int)func_021DB690);}break;
    }
    if(p->f8)func_021FC830(p->f8);
}















/*
 * lever: enum mask local materializes one before the call; int mask left nine bytes different
 */
void func_021DB594(int *task, int *state, struct CodeinWorkA *p)
{
    switch(*state) {
    case 0: *state=1; break;
    case 1:
        func_021FEE74((char *)(((struct CodeinSubA *)(p->f1C))->f14));
        *state=2;
        break;
    case 2:
        if(((*(int *)&p->f10))++ !=0) {
            (*(int *)&p->f10)=0;
            func_021FE794((char *)((*(int *)&((struct CodeinSubA *)(p->f1C))->f8)),3,3,1,26);
            *state=3;
        }
        break;
    case 3:
    {
        enum { MASK=1 } mask=MASK;
        if(func_021FE7B0(((struct CodeinSubA *)(p->f1C))->f8)&mask) *state=4;
        break;
    }
    case 4:
        func_021F9BA0((*(void * *)&((struct CodeinSubA *)(p->f1C))->f10));
        func_021FD73C(task,(int)func_021DB690);
        break;
    }
}















void func_021DB61C(int *task, int *state, struct CodeinWorkA *p)
{
    switch(*state) {
    case 0:
        func_021FE794((char *)((*(int *)&((struct CodeinSubA *)(p->f1C))->f8)),2,3,1,1);
        *state=1;
        break;
    case 1:
        if(func_021FE7B0(((struct CodeinSubA *)(p->f1C))->f8)) *state=2;
        break;
    case 2:
        func_021FEE9C((char *)(((struct CodeinSubA *)(p->f1C))->f14));
        func_021FEE4C((char *)(((struct CodeinSubA *)(p->f1C))->f14));
        func_021F9BF4((unsigned int *)(((struct CodeinSubA *)(p->f1C))->f10),1);
        func_021FD73C(task,(int)func_021DB690);
        break;
    }
}















void func_021DB690(int *task)
{
    func_021FD744((int *)task);
}















/*
 * extent: two bytes of zero alignment padding at 0x021DB73E
 */
int func_021DB698(int *task,int b,char *p)
{
    struct CodeinStateB *s;
    s=PROCSYS_AllocProcWork((struct Obj0203159C *)task,24,func_021F9B9C((struct Obj24810 *)(*(char * *)&((struct CodeinWorkB *)p)->f1C)));
    func_02082BCC(s,0,24);
    s->fC=p;
    s->f14=func_021F9B9C((struct Obj24810 *)(*(char * *)&((struct CodeinWorkB *)p)->f1C));
    func_021FC1F8(*(int * *)&((struct CodeinWorkB *)p)->f18,0);
    func_021FC1F8(*(int * *)&((struct CodeinWorkB *)p)->f18,1);
    func_021FC148((char *)(*(int * *)&((struct CodeinWorkB *)p)->f18),0,s->f14);
    func_021FC148((char *)(*(int * *)&((struct CodeinWorkB *)p)->f18),1,s->f14);
    if(((struct CodeinWorkB *)p)->f0<5) func_021FB964(*(int * *)&((struct CodeinWorkB *)p)->f18,3,s->f14);
    else func_021FB964(*(int * *)&((struct CodeinWorkB *)p)->f18,4,s->f14);
    s->f4=(int)func_021FD760((*(int *)&((struct CodeinWorkB *)p)->f14),(char *)(*(int *)&((struct CodeinWorkB *)p)->f18),1,s->f14);
    s->f0=(int)func_021F9CB8(((struct CodeinWorkB *)p)->f0,(*(int *)&((struct CodeinWorkB *)p)->f14),*(int *)&((struct CodeinWorkB *)p)->f18,((struct CodeinWorkB *)p)->f20,(*(int *)&((struct CodeinWorkB *)p)->f24),s->f4,s->f14);
    if(((struct CodeinWorkB *)p)->fC==4) func_021FE840(((struct CodeinWorkB *)p)->f10,2,0);
    else func_021FE840(((struct CodeinWorkB *)p)->f10,3,0);
    return 1;
}















/*
 * lever: Explicit call arms preserve the original conditional argument branch.
 */
int func_021DB740(struct S020315D4 *task,int b,struct CodeinArgB *q,struct CodeinWorkA *p) { if(q->f0<5) func_021FBDA4(q->f18,3); else func_021FBDA4(q->f18,4); func_021F9F48(*(u8 * *)&p->f0); func_021FD820(*(char * *)&p->f4); func_020315D4(task); return 1; }















/*
 * lever: explicit case-3 call arms preserve the original block shape; ARM9 division helper uses the proven _u32_div_f ABI.
 */
int func_021DB770(int *task,int *state,struct CodeinWorkB *p,struct CodeinArgA *q)
{
    u32 x,y;
    switch(*state) {
    case 0: func_021FE784(p->f10,p->fC,3,0);*state=1;break;
    case 1: if(func_021FE7B0(*(int * *)&p->f10))*state=2;break;
    case 2:
        if(p->f0<=4 && !func_021FA018(*(char * *)&q->f0) && func_02035D20(&x,&y)) {
            if(x<8 || x>248) {func_020061E4(0x703);*state=6;break;}
        }
        func_021F9FE8(*(char * *)&q->f0);
        if(func_021FA004(*(char * *)&q->f0,(int *)((char *)p+4),(int *)((char *)p+8))) *state=3;
        break;
    case 3:
        if(p->f4==12)func_021FE784(p->f10,4,3,1);
        else func_021FE784(p->f10,2,3,1);
        *state=4;break;
    case 4: if(func_021FE7B0(*(int * *)&p->f10))*state=5;break;
    case 5:
        switch(func_021FA004(*(char * *)&q->f0,(int *)((char *)p+4),(int *)((char *)p+8))) {
        case 1: func_021F9BF4(*(unsigned * *)&p->f1C,(unsigned short)p->f4);return 1;
        case 2: func_021F9BA0((*(void * *)&p->f1C));**(int * *)&p->f28=func_021FA01C(*(char * *)&q->f0);return 1;
        }
        break;
    case 6: {
        int v=func_021FC238(*(char * *)&p->f18);u32 i;
        for(i=0;i<7;i++) {if(v==d_021E3280[i]) {v=d_021E3280[(i+1)%7];break;}}
        func_021FC230(*(char * *)&p->f18,v);
        func_021FE7F4(*(int * *)&p->f10,func_021FC224(*(char * *)&p->f18));
        func_021FE784(p->f10,3,3,1);*state=7;break;
    }
    case 7: if(func_021FE7B0(*(int * *)&p->f10))*state=8;break;
    case 8: (*(void * *)&q->f8)=func_020056A0((void (*)(void))func_021DB924,q,0);q->f10=0;*state=9;break;
    case 9: if(q->f10) {func_02030EAC((*(void * *)&q->f8));*state=10;}break;
    case 10: func_021FE784(p->f10,3,3,0);*state=11;break;
    case 11: if(func_021FE7B0(*(int * *)&p->f10))*state=2;break;
    }
    func_021FD854(*(char * *)&q->f4);return 0;
}
















void func_021DB924(int a0, struct CodeinWorkF *p)
{
    int v = p->f10;
    char *q = *(char * *)&p->fC;

    if (v == 0) {
        func_021FC240((char *)(((struct CodeinArgB *)q)->f18), (void *)((*(int *)&((struct CodeinArgB *)q)->f10)),
                      p->f14);
    }
    p->f10 = 1;
}















/*
 * note 2026-10-05: re-run, bytes identical to the original; the only unresolved relocation is the BL to arm9 0x0200B98C (Thumb, 64 bytes, no code-start label, no asm/arm9 witness). Integrator: seed a label at 0x0200B98C; no source change needed.
 * lever: shared state-flag store and distinct case-5 null path preserve the original switch layout.
 * blocker-C: copied prior verified Thumb EXACT from ov183_func_021DF838.c header, blocker-r2.log; table 0x0209DDCC data a4.
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned long long u64;
 * extern const u16 BattleRecModeTable[];
 * u64 BATTLE_REC_GetHeaderParam(char *p,int selector,int index) {
 *   int i;u16 v;
 *   switch(selector) {
 *   case 0: v=((u16 *)p)[index];if(v>0x289)return 0;return v;
 *   case 1: return *(u8 *)(p+index+0x18)&0x7f;
 *   case 2: v=*(u16 *)(p+0x24);if(v>0x270f)return 0x270f;return v;
 *   case 3: for(i=0;i<0x29;i++)if(*(u16 *)(p+0x26)==BattleRecModeTable[i])return i;return 0;
 *   case 4: return *(u64 *)(p+0x38);
 *   case 5: return *(u8 *)(p+0x2a);
 *   case 6: return (*(u8 *)(p+index+0x18)&0x80)>>7;
 *   case 7: return *(u8 *)(p+0x2b);
 *   default:return 0;
 *   }
 * }
 */
int func_021DB940(int *task,int *state,char *q)
{
    char *p,*s;
    int i;
    p=PROCSYS_AllocProcWork((struct Obj0203159C *)task,0xe8,func_021F9B9C((struct Obj24810 *)(*(char **)(q+0x14))));
    func_02082BCC(p,0,0xe8);
    *(unsigned short *)(p+0xb4)=func_021F9B9C((struct Obj24810 *)(*(char **)(q+0x14)));
    *(int *)(p+0xb0)=0;
    *(char **)(p+0xd0)=q;
    *(void **)p=BMP_OAM_CreateSys(*(unsigned short *)(p+0xb4),*(void **)(q+0x18));
    *(void **)(p+4)=(void *)func_0201C440((void *)(*(unsigned short *)(p+0xb4)));
    *(void **)(p+8)=func_021FD6D8((int)p,0,*(unsigned short *)(p+0xb4));
    for(i=0;i<2;i++) *(char **)(p+i*4+0xc)=func_021FD760(*(unsigned *)(q+0x18),*(char **)(q+0x10),i,*(unsigned short *)(p+0xb4));
    switch(*(int *)(*(char **)(p+0xd0)+8)) {
    case 4:
        s=*(char **)(*(char **)(p+0xd0)+0x30);
        *(char **)(p+0xc4)=s+*(int *)(s+0x171c)*0xc4+0x80;
        s=*(char **)(*(char **)(p+0xd0)+0x30);
        *(char **)(p+0xc0)=s+*(int *)(s+0x171c)*0xc4;
        *(int *)(p+0xcc)=1;
        if(**(int **)(*(char **)(p+0xd0)+0x3c) && *(int *)(*(char **)(p+0xd0)+0x34)) {
            s=*(char **)(*(char **)(p+0xd0)+0x30);
            *(s+*(int *)(s+0x171c)+0x16f8)=1;
        }
        s=*(char **)(*(char **)(p+0xd0)+0x30);
        *(int *)(p+0xc8)=*(unsigned char *)(s+*(int *)(s+0x171c)+0x16f8);
        break;
    case 0:
        *(char **)(p+0xc4)=BATTLE_REC_GetHeader();*(char **)(p+0xc0)=(char *)BATTLE_REC_GetWork();
        *(int *)(p+0xc8)=1;i=0;goto set_cc;
    case 1: case 2: case 3:
        *(char **)(p+0xc4)=BATTLE_REC_GetHeader();*(char **)(p+0xc0)=(char *)BATTLE_REC_GetWork();
        *(int *)(p+0xc8)=BATTLE_REC_GetHeaderParam(*(void **)(p+0xc4),5,0);*(int *)(p+0xcc)=0;break;
    case 5:
        if(*(int *)(*(char **)(p+0xd0)+0x34)==0) {
            *(int *)(p+0xc4)=0;*(int *)(p+0xc0)=0;
        }else {
            *(char **)(p+0xc4)=BATTLE_REC_GetHeader();*(char **)(p+0xc0)=(char *)BATTLE_REC_GetWork();
            *(int *)(p+0xc8)=**(int **)(*(char **)(p+0xd0)+0x3c);
        }
        i=1;
    set_cc:
        *(int *)(p+0xcc)=i;
        break;
    }
    if(*(int *)(*(char **)(p+0xd0)+8)==5) {
        if(*(int *)(*(char **)(p+0xd0)+0x34)==0)func_021FD73C(*(int **)(p+8),(int)func_021DBFB0);
        else func_021FD73C(*(int **)(p+8),(int)func_021DBC68);
    }else if((u32)(*(int *)(*(char **)(p+0xd0)+8)-1)<=2 && *(int *)(*(char **)(p+0xd0)+0x34) && **(int **)(*(char **)(p+0xd0)+0x3c) && *(int *)(p+0xc8)==0) {
        func_021FD73C(*(int **)(p+8),(int)func_021DC4FC);
    }else func_021FD73C(*(int **)(p+8),(int)func_021DBC68);
    return 1;
}















int func_021DBB3C(int task,int b,char *q,char *p)
{
    int i;
    func_021DCE28(p,q);
    func_021DCE48(p,q);
    func_021DD054(p,q);
    func_021DD0F4(p,q);
    func_021DD1D4(p,q);
    ((struct CodeinArgA *)q)->f4=((struct CodeinWorkB *)p)->fC8;
    func_020409B4(4);
    func_020409B4(1);
    if(((struct CodeinWorkB *)p)->f18) {
        func_021FD15C(((struct CodeinWorkB *)p)->f18,((struct CodeinSubA *)(((struct CodeinWorkB *)p)->fD0))->f10);
        ((struct CodeinWorkB *)p)->f18=0;
    }
    for(i=0;i<2;i++) func_021FD820(*(char **)(p+i*4+0xc));
    func_021FD714((void *)((*(int *)&((struct CodeinWorkB *)p)->f8)));
    func_0201C4C0((*(void * *)&((struct CodeinWorkB *)p)->f4));
    BMP_OAM_DeleteSys((void *)(((struct CodeinWorkB *)p)->f0));
    func_020315D4((struct S020315D4 *)task);
    return 1;
}















/*
 * extent: two bytes of zero alignment padding at 0x021DBC66
 */
int func_021DBBC4(int a,int b,int c,struct CodeinWorkB *p)
{
    int i;
    if(GAME_DATA_IsSaving(((struct CodeinSubA *)(p->fD0))->f28)==0 && func_021FF88C(((struct CodeinSubA *)(p->fD0))->f24)==2) {
        func_021F9C6C((*(void * *)&((struct CodeinSubA *)(p->fD0))->f14));
        return 1;
    }
    func_021FD71C(p->f8);
    if(func_021FD72C(p->f8)) return 1;
    for(i=0;i<2;i++) func_021FD854(*(void **)((char *)p+i*4+0xc));
    PRINTSYS_QUE_Main((*(void * *)&p->f4));
    for(i=0;i<2;i++) if(*(void **)((char *)p+i*4+0x28)) func_021FC830(*(void **)((char *)p+i*4+0x28));
    for(i=0;i<5;i++) if(*(void **)((char *)p+i*4+0x30)) func_021FC830(*(void **)((char *)p+i*4+0x30));
    if((*(void * *)&p->f44)) func_021FD6B0((*(void * *)&p->f44));
    if(p->f18) func_021FD1BC(p->f18);
    return 0;
}














/*
 * Flush the object, dispatch on the p+0xB0 flag, then chain to 0x21FD73C.
 */
void func_021DBC68(int a, int b, char *p)
{
    func_021DCEE4(p, (char *)((*(int *)&((struct CodeinWorkA *)p)->fD0)));
    if (((struct CodeinWorkA *)p)->fB0 != 0)
        func_021DCDD8(p, (char *)((*(int *)&((struct CodeinWorkA *)p)->fD0)));
    else
        func_021DC8EC(p, (char *)((*(int *)&((struct CodeinWorkA *)p)->fD0)));
    func_021FD73C((int *)a, (int)func_021DBCA8);
}













void func_021DBCA8(int *task, int *state, struct CodeinWorkA *p)
{
    switch(*state) {
    case 0:
        func_021FE784((*(int *)&((struct CodeinSubA *)(p->fD0))->fC),2,3,0);
        *state=1;
        break;
    case 1:
        if(func_021FE7B0(((struct CodeinSubA *)(p->fD0))->fC)) *state=2;
        break;
    case 2:
        func_021FD73C(task,(int)func_021DBD7C);
        break;
    }
}













void func_021DBCF4(int *task, int *state, struct CodeinWorkA *p)
{
    switch(*state) {
    case 0:
        func_021FE784((*(int *)&((struct CodeinSubA *)(p->fD0))->fC),2,3,1);
        *state=1;
        break;
    case 1:
        if(func_021FE7B0(((struct CodeinSubA *)(p->fD0))->fC)) *state=2;
        break;
    case 2:
        func_021FD73C(task,(int)func_021DBD40);
        break;
    }
}












void func_021DBD40(int *task,int b,char *p) { if(((struct CodeinWorkB *)p)->fB0) func_021DCE28(p,((struct CodeinWorkB *)p)->fD0); else func_021DCE48(p,((struct CodeinWorkB *)p)->fD0); func_021DD054(p,((struct CodeinWorkB *)p)->fD0); func_021FD744(task); }












/*
 * note 2026-10-05: re-run, bytes identical to the original; the only unresolved relocation is the BL to arm9 0x0200B98C (Thumb, 64 bytes, no code-start label, no asm/arm9 witness). Integrator: seed a label at 0x0200B98C; no source change needed.
 * lever: decode each callback literal from its actual PC-relative pool slot; repeated shared loads obscure distinct callback targets.
 * blocker-C: copied prior verified Thumb EXACT from ov183_func_021DF838.c header, blocker-r2.log; table 0x0209DDCC data a4.
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned long long u64;
 * extern const u16 BattleRecModeTable[];
 * u64 BATTLE_REC_GetHeaderParam(char *p,int selector,int index) {
 *   int i;u16 v;
 *   switch(selector) {
 *   case 0: v=((u16 *)p)[index];if(v>0x289)return 0;return v;
 *   case 1: return *(u8 *)(p+index+0x18)&0x7f;
 *   case 2: v=*(u16 *)(p+0x24);if(v>0x270f)return 0x270f;return v;
 *   case 3: for(i=0;i<0x29;i++)if(*(u16 *)(p+0x26)==BattleRecModeTable[i])return i;return 0;
 *   case 4: return *(u64 *)(p+0x38);
 *   case 5: return *(u8 *)(p+0x2a);
 *   case 6: return (*(u8 *)(p+index+0x18)&0x80)>>7;
 *   case 7: return *(u8 *)(p+0x2b);
 *   default:return 0;
 *   }
 * }
 */
void func_021DBD7C(int *task,int *state,char *p)
{
    u32 x,y;
    if(func_02035D20(&x,&y)) {
        if(func_021DD27C(p,x,y)) {
            *(int *)(p+0xb0)^=1;
            func_021FD73C(task,(int)func_021DBEB0);
        }
        if(func_021FB4B4((unsigned int *)(*(int *)(p+0x1c)),x,y)) {
            Point args;
            args.x=x;args.y=y;
            func_021FD860((void *)(*(int *)(p+0x10)), 1, &args);
            **(int **)(p+0xd0)=0;
            func_021F9BA0(*(void **)(*(char **)(p+0xd0)+0x14));
            func_021FD73C(task,(int)func_021DBCF4);
        }
        if(*(int *)(p+0x20) && func_021FB4B4((unsigned int *)(*(int *)(p+0x20)),x,y)) {
            Point args;
            args.x=x;args.y=y;
            func_021FD860((void *)(*(int *)(p+0x10)), 1, &args);
            func_021F9BF4(*(unsigned **)(*(char **)(p+0xd0)+0x14),10);
            *(u64 *)(*(char **)(p+0xd0)+0x1c)=BATTLE_REC_GetHeaderParam(*(void **)(p+0xc4),4,0);
            func_021FD73C(task,(int)func_021DBCF4);
        }
        if(func_021DD2BC(p,x,y)) {
            if((u32)(*(u32 *)(*(char **)(p+0xd0)+8)-4)<=1)func_021FD73C(task,(int)func_021DC228);
            else if(*(int *)(p+0xc8)==0)func_021FD73C(task,(int)func_021DC638);
            else {
                **(int **)(p+0xd0)=1;
                func_021F9C50((S_021DB2E0 *)(*(S_021DB2E0 **)(*(char **)(p+0xd0)+0x14)));
                func_021FD73C(task,(int)func_021DBCF4);
            }
        }
    }
}












void func_021DBEB0(int *task,int *state,char *p)
{
    int a,b;
    switch(*state) {
    case 0:
        func_021FE784((*(int *)&((struct CodeinSubA *)(((struct CodeinWorkB *)p)->fD0))->fC),2,1,1);
        (*state)++;break;
    case 1:
        if(func_021FE7B0(((struct CodeinSubA *)(((struct CodeinWorkB *)p)->fD0))->fC))(*state)++;
        break;
    case 2:
        a=func_021FC20C(*(char * *)&((struct CodeinSubA *)(((struct CodeinWorkB *)p)->fD0))->f10);
        b=func_021FC214(*(char * *)&((struct CodeinSubA *)(((struct CodeinWorkB *)p)->fD0))->f10);
        if(((struct CodeinWorkB *)p)->fB0) {
            func_021DCE48(p,((struct CodeinWorkB *)p)->fD0);
            func_021FC754(*(char * *)&((struct CodeinWorkB *)p)->f28,(void *)b,(void *)0x72,(void *)a,0x3da0);
            func_021DCDD8(p,((struct CodeinWorkB *)p)->fD0);
        }else{
            func_021DCE28(p,((struct CodeinWorkB *)p)->fD0);
            func_021FC754(*(char * *)&((struct CodeinWorkB *)p)->f28,(void *)b,(void *)0x71,(void *)a,0x3da0);
            func_021DC8EC(p,(char *)(*(int *)&((struct CodeinWorkB *)p)->fD0));
        }
        func_021FE784((*(int *)&((struct CodeinSubA *)(((struct CodeinWorkB *)p)->fD0))->fC),2,1,0);
        (*state)++;break;
    case 3:
        if(func_021FE7B0(((struct CodeinSubA *)(((struct CodeinWorkB *)p)->fD0))->fC))func_021FD73C(task,(int)func_021DBD7C);
        break;
    }
}











/*
 * note 2026-10-05: shape copied from matched twin ov183_func_021DC228.c (same state machine, same callees). v1 was 4 bytes off (stack slots of source and index swapped); declaring source before index fixed it. Older draft docs/notes/pkt_ov183_021DBFB0.c.txt (167 B off) superseded.
 */
void func_021DBFB0(int *a,int *state,char *p)
{
    u64 t;
    int message;
    char *source;
    int index;
    u32 x,y;
    Point args;
    switch(*state) {
    case 0:
        func_021DD0AC(p,*(char **)(p+0xd0));
        func_021FD170(*(void **)(p+0x18),(char *)(*(int *)(*(char **)(p+0xd0)+0x10)),(void *)0x14b);*state=1;break;
    case 1: func_021FE784((int)(*(int **)(*(char **)(p+0xd0)+12)),2,3,0);*state=2;break;
    case 2: if(func_021FE7B0(*(int **)(*(char **)(p+0xd0)+12))) *state=3;break;
    case 3:
        func_02082BCC(&t,0,8);
        t=*(u64 *)(*(char **)(p+0xd0)+0x1c);
        func_021FF54C(*(void **)(*(char **)(p+0xd0)+0x24),3,(const int *)(&t));
        *(int *)(p+0xbc)=0;*state=4;break;
    case 4:
        ++*(int *)(p+0xbc);
        if(func_021FF648(*(void **)(*(char **)(p+0xd0)+0x24)) && *(u32 *)(p+0xbc)>96) {
            func_021FD860((void *)(*(int *)(p+12)), 0, 0);*state=5;
        }
        break;
    case 5:
        if(!func_021FF72C(*(void **)(*(char **)(p+0xd0)+0x24),&message)) {
            if(func_021FF698(*(char **)(*(char **)(p+0xd0)+0x24),(int)&source,&index)) {
                *(char **)(p+0xc0)=source;
                *(char **)(p+0xc4)=source+0x80;*state=6;
            } else {
                func_021FD170(*(void **)(p+0x18),(char *)(*(int *)(*(char **)(p+0xd0)+0x10)),(void *)0x114);*state=11;
            }
        } else {
            func_021FD170(*(void **)(p+0x18),(char *)(*(int *)(*(char **)(p+0xd0)+0x10)),(void *)message);*state=11;
        }
        break;
    case 11:
        if(TOUCHPANEL_GetTrg()) {
            func_02035D20(&x,&y);args.x=x;args.y=y;
            func_021FD860((void *)(*(int *)(p+0x10)), 1, &args);func_020061E4(0x703);
            func_021F9BA0((unsigned int *)(*(S_021DBFB0 **)(*(char **)(p+0xd0)+0x14)));*state=12;
        }
        break;
    case 6: func_021FE784((int)(*(int **)(*(char **)(p+0xd0)+12)),2,3,1);*state=7;break;
    case 7:
        if(func_021FE7B0(*(int **)(*(char **)(p+0xd0)+12))) {
            func_021DD0F4(p,*(char **)(p+0xd0));
            func_021DCEE4(p,*(char **)(p+0xd0));
            func_021DC8EC(p,*(char **)(p+0xd0));*state=8;
        }
        break;
    case 8: func_021FE784((int)(*(int **)(*(char **)(p+0xd0)+12)),2,3,0);*state=9;break;
    case 9: if(func_021FE7B0(*(int **)(*(char **)(p+0xd0)+12))) *state=10;break;
    case 10: func_021FD73C(a,(int)func_021DBD7C);break;
    case 12: func_021FE784((int)(*(int **)(*(char **)(p+0xd0)+12)),2,3,1);*state=13;break;
    case 13: if(func_021FE7B0(*(int **)(*(char **)(p+0xd0)+12))) *state=14;break;
    case 14: func_021DD0F4(p,*(char **)(p+0xd0));func_021FD744((int *)a);break;
    }
}











/*
 * note 2026-10-05: re-run, bytes identical to the original; the only unresolved relocation is the BL to arm9 0x0200B98C (Thumb, 64 bytes, no code-start label, no asm/arm9 witness). Integrator: seed a label at 0x0200B98C; no source change needed.
 * diagnostic: ov186 0x021FF648 +013C resolved through a sibling's new shard in the TU; only ARM9 remains. TU --suggest-split leaves caller out.
 * blocker-C: prior verified Thumb EXACT from ov183_func_021DF838.c header, blocker-r2.log, dsi/1.1p1 -O4,p; table 0x0209DDCC data a4.
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned long long u64;
 * extern const u16 BattleRecModeTable[];
 * u64 BATTLE_REC_GetHeaderParam(char *p,int selector,int index) {
 *   int i;u16 v;
 *   switch(selector) {
 *   case 0: v=((u16 *)p)[index];if(v>0x289)return 0;return v;
 *   case 1: return *(u8 *)(p+index+0x18)&0x7f;
 *   case 2: v=*(u16 *)(p+0x24);if(v>0x270f)return 0x270f;return v;
 *   case 3: for(i=0;i<0x29;i++)if(*(u16 *)(p+0x26)==BattleRecModeTable[i])return i;return 0;
 *   case 4: return *(u64 *)(p+0x38);
 *   case 5: return *(u8 *)(p+0x2a);
 *   case 6: return (*(u8 *)(p+index+0x18)&0x80)>>7;
 *   case 7: return *(u8 *)(p+0x2b);
 *   default:return 0;
 *   }
 * }
 * abi: B938 retains caller-loaded r3; DD0AC/DD0F4 retain caller-loaded r1; 35C60 return is consumed.
 */
void func_021DC228(int *a,int *state,char *p)
{
    u64 t;
    int message;
    int index;
    char *source;
    u32 x,y;
    Point args;
    switch(*state) {
    case 0: func_021FE784((int)(*(int **)(*(char **)(p+0xd0)+12)),2,3,1);*state=1;break;
    case 1: if(func_021FE7B0(*(int **)(*(char **)(p+0xd0)+12))) *state=2;break;
    case 2:
        if(*(int *)(p+0xb0)) func_021DCE28(p,*(char **)(p+0xd0));
        else func_021DCE48(p,*(char **)(p+0xd0));
        func_021DD054(p,*(char **)(p+0xd0));
        func_021DD0AC(p,*(char **)(p+0xd0));
        func_021FD170(*(void **)(p+0x18),(char *)(*(int *)(*(char **)(p+0xd0)+0x10)),(void *)0x14b);
        *state=3;break;
    case 3: func_021FE784((int)(*(int **)(*(char **)(p+0xd0)+12)),2,3,0);*state=4;break;
    case 4: if(func_021FE7B0(*(int **)(*(char **)(p+0xd0)+12))) *state=5;break;
    case 5:
        func_02082BCC(&t,0,8);
        t=BATTLE_REC_GetHeaderParam(*(void **)(p+0xc4),4,0);
        func_021FF54C(*(void **)(*(char **)(p+0xd0)+0x24),3,(const int *)(&t));
        *(int *)(p+0xbc)=0;*state=6;break;
    case 6:
        ++*(int *)(p+0xbc);
        if(func_021FF648(*(void **)(*(char **)(p+0xd0)+0x24)) && *(u32 *)(p+0xbc)>96) {
            func_021FD860((void *)(*(int *)(p+12)), 0, 0);*state=7;
        }
        break;
    case 7:
        if(!func_021FF72C(*(void **)(*(char **)(p+0xd0)+0x24),&message)) {
            if(func_021FF698(*(char **)(*(char **)(p+0xd0)+0x24),(int)&source,&index)) {
                BATTLE_REC_SetData(source,source+0x80,source+0xc4,(unsigned int)GAME_DATA_GetSaveControl(*(void **)(*(char **)(p+0xd0)+0x28)));
                **(long long **)(*(char **)(p+0xd0)+0x2c)=index;
                **(int **)(p+0xd0)=1;
                func_021F9C50((S_021DB2E0 *)(*(S_021DBFB0 **)(*(char **)(p+0xd0)+0x14)));*state=8;
            } else {
                func_021FD170(*(void **)(p+0x18),(char *)(*(int *)(*(char **)(p+0xd0)+0x10)),(void *)0x114);*state=11;
            }
        } else {
            func_021FD170(*(void **)(p+0x18),(char *)(*(int *)(*(char **)(p+0xd0)+0x10)),(void *)message);*state=11;
        }
        break;
    case 11:
        if(TOUCHPANEL_GetTrg()) {
            func_02035D20(&x,&y);args.x=x;args.y=y;
            func_021FD860((void *)(*(int *)(p+0x10)), 1, &args);func_020061E4(0x703);*state=12;
        }
        break;
    case 8: func_021FE784((int)(*(int **)(*(char **)(p+0xd0)+12)),2,3,1);*state=9;break;
    case 9: if(func_021FE7B0(*(int **)(*(char **)(p+0xd0)+12))) *state=10;break;
    case 10:
        if(!GFL_USE_IsSeqPlaying(0x701)) {func_021DD0F4(p,*(char **)(p+0xd0));func_021FD744((int *)(*(int *)(p+8)));}
        break;
    case 12: func_021FE784((int)(*(int **)(*(char **)(p+0xd0)+12)),2,3,1);*state=13;break;
    case 13: if(func_021FE7B0(*(int **)(*(char **)(p+0xd0)+12))) *state=14;break;
    case 14: func_021DD0F4(p,*(char **)(p+0xd0));func_021FD73C(a,(int)func_021DBC68);break;
    }
}











/*
 * note 2026-10-05: re-run, bytes identical to the original; the only unresolved relocation is the BL to arm9 0x0200B98C (Thumb, 64 bytes, no code-start label, no asm/arm9 witness). Integrator: seed a label at 0x0200B98C; no source change needed.
 * blocker-C: prior verified Thumb EXACT from ov183_func_021DF838.c header, blocker-r2.log, dsi/1.1p1 -O4,p; table 0x0209DDCC data a4.
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned long long u64;
 * extern const u16 BattleRecModeTable[];
 * u64 BATTLE_REC_GetHeaderParam(char *p,int selector,int index) {
 *   int i;u16 v;
 *   switch(selector) {
 *   case 0: v=((u16 *)p)[index];if(v>0x289)return 0;return v;
 *   case 1: return *(u8 *)(p+index+0x18)&0x7f;
 *   case 2: v=*(u16 *)(p+0x24);if(v>0x270f)return 0x270f;return v;
 *   case 3: for(i=0;i<0x29;i++)if(*(u16 *)(p+0x26)==BattleRecModeTable[i])return i;return 0;
 *   case 4: return *(u64 *)(p+0x38);
 *   case 5: return *(u8 *)(p+0x2a);
 *   case 6: return (*(u8 *)(p+index+0x18)&0x80)>>7;
 *   case 7: return *(u8 *)(p+0x2b);
 *   default:return 0;
 *   }
 * }
 * abi: DD0AC/DD0F4 keep the visibly loaded second descriptor argument despite body using only the first.
 */
void func_021DC4FC(int *a,int *state,char *p)
{
    switch(*state) {
    case 0:
        func_021DD0AC(p,*(char **)(p+0xd0));
        func_021FD170(*(void **)(p+0x18),(char *)(*(int *)(*(char **)(p+0xd0)+0x10)),(void *)0x152);
        func_021FE784((int)(*(int **)(*(char **)(p+0xd0)+12)),2,3,0);
        *state=1;break;
    case 1: if(func_021FE7B0(*(int **)(*(char **)(p+0xd0)+12))) *state=2;break;
    case 2: *state=3;break;
    case 3: *(u16 *)(p+0xb6)=0;*(u16 *)(p+0xb8)=0;*state=4;break;
    case 4:
        if(*(int *)(*(char **)(p+0xd0)+8)>3) func_02034714(d_021E3960,0,d_021E3960);
        if(func_021D7630((void *)(*(int *)(*(char **)(p+0xd0)+0x28)),*(int *)(*(char **)(p+0xd0)+8),(u16 *)(p+0xb6),(u16 *)(p+0xb8),*(u16 *)(p+0xb4))==2) {
            BATTLE_REC_DecodeWork();
            *(int *)(p+0xc8)=(int)BATTLE_REC_GetHeaderParam(*(void **)(p+0xc4),5,0);
            *state=5;
        }
        break;
    case 5: func_021FE784((int)(*(int **)(*(char **)(p+0xd0)+12)),2,3,1);*state=6;break;
    case 6: if(func_021FE7B0(*(int **)(*(char **)(p+0xd0)+12))) *state=7;break;
    case 7: func_021DD0F4(p,*(char **)(p+0xd0));func_021FD73C(a,(int)func_021DBC68);break;
    }
}










/*
 * abi: DD0AC/DD0F4 retain caller-loaded r1.
 */
void func_021DC638(int *a,int *state,char *p)
{
    u32 x,y;
    switch(*state) {
    case 0: func_021FE784((int)(((struct CodeinSubA *)(((struct CodeinWorkB *)p)->fD0))->fC),2,3,1);*state=1;break;
    case 1: if(func_021FE7B0(((struct CodeinSubA *)(((struct CodeinWorkB *)p)->fD0))->fC)) *state=2;break;
    case 2:
        if(((struct CodeinWorkB *)p)->fB0) func_021DCE28(p,((struct CodeinWorkB *)p)->fD0);
        else func_021DCE48(p,((struct CodeinWorkB *)p)->fD0);
        func_021DD054(p,((struct CodeinWorkB *)p)->fD0);func_021DD128(p,((struct CodeinWorkB *)p)->fD0);*state=3;break;
    case 3: func_021FE784((int)(((struct CodeinSubA *)(((struct CodeinWorkB *)p)->fD0))->fC),2,3,0);++*state;break;
    case 4: if(func_021FE7B0(((struct CodeinSubA *)(((struct CodeinWorkB *)p)->fD0))->fC)) ++*state;break;
    case 5: ++*state;break;
    case 6:
        if(func_02035D20(&x,&y)) {
            if(func_021DD2FC(p,x,y)) *state=7;
            else if(func_021DD33C(p,x,y)) *state=10;
        }
        break;
    case 7: func_021FE784((int)(((struct CodeinSubA *)(((struct CodeinWorkB *)p)->fD0))->fC),2,3,1);++*state;break;
    case 8: if(func_021FE7B0(((struct CodeinSubA *)(((struct CodeinWorkB *)p)->fD0))->fC)) ++*state;break;
    case 9: func_021DD1D4(p,((struct CodeinWorkB *)p)->fD0);*state=13;break;
    case 10: func_021FE784((int)(((struct CodeinSubA *)(((struct CodeinWorkB *)p)->fD0))->fC),2,3,1);++*state;break;
    case 11: if(func_021FE7B0(((struct CodeinSubA *)(((struct CodeinWorkB *)p)->fD0))->fC)) ++*state;break;
    case 12: func_021DD1D4(p,((struct CodeinWorkB *)p)->fD0);func_021FD73C(a,(int)func_021DBC68);break;
    case 13: func_021DD0AC(p,((struct CodeinWorkB *)p)->fD0);*state=14;break;
    case 14:
        func_021FD170(((struct CodeinWorkB *)p)->f18,(char *)(((struct CodeinSubA *)(((struct CodeinWorkB *)p)->fD0))->f10),(void *)0x152);
        func_021FE784((int)(((struct CodeinSubA *)(((struct CodeinWorkB *)p)->fD0))->fC),2,3,0);*state=15;break;
    case 15: if(func_021FE7B0(((struct CodeinSubA *)(((struct CodeinWorkB *)p)->fD0))->fC)) *state=16;break;
    case 16: *state=17;break;
    case 17: GAME_DATA_SaveStart((*(int *)&((struct CodeinSubA *)(((struct CodeinWorkB *)p)->fD0))->f28));*state=18;break;
    case 18:
        if(GAME_DATA_SaveMain(*(u8 * *)&((struct CodeinSubA *)(((struct CodeinWorkB *)p)->fD0))->f28)==2) {func_021FD860((void *)(((struct CodeinWorkB *)p)->fC), 0, 0);*state=19;}
        break;
    case 19: func_021FE784((int)(((struct CodeinSubA *)(((struct CodeinWorkB *)p)->fD0))->fC),2,3,1);*state=20;break;
    case 20: if(func_021FE7B0(((struct CodeinSubA *)(((struct CodeinWorkB *)p)->fD0))->fC)) *state=21;break;
    case 21:
        if(!GFL_USE_IsSeqPlaying(0x701)) {
            func_021DD0F4(p,((struct CodeinWorkB *)p)->fD0);
            **(int * *)&((struct CodeinWorkB *)p)->fD0=1;
            func_021F9C50((S_021DB2E0 *)(*(S * *)&((struct CodeinSubA *)(((struct CodeinWorkB *)p)->fD0))->f14));
            func_021FD744((int *)a);
        }
        break;
    }
}










/*
 * note 2026-10-05: re-run, bytes identical to the original; the only unresolved relocation is the BL to arm9 0x0200B98C (Thumb, 64 bytes, no code-start label, no asm/arm9 witness). Integrator: seed a label at 0x0200B98C; no source change needed.
 * blocker-C: prior verified Thumb EXACT from ov183_func_021DF838.c header, blocker-r2.log, dsi/1.1p1 -O4,p; table 0x0209DDCC data a4.
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned long long u64;
 * extern const u16 BattleRecModeTable[];
 * u64 BATTLE_REC_GetHeaderParam(char *p,int selector,int index) {
 *   int i;u16 v;
 *   switch(selector) {
 *   case 0: v=((u16 *)p)[index];if(v>0x289)return 0;return v;
 *   case 1: return *(u8 *)(p+index+0x18)&0x7f;
 *   case 2: v=*(u16 *)(p+0x24);if(v>0x270f)return 0x270f;return v;
 *   case 3: for(i=0;i<0x29;i++)if(*(u16 *)(p+0x26)==BattleRecModeTable[i])return i;return 0;
 *   case 4: return *(u64 *)(p+0x38);
 *   case 5: return *(u8 *)(p+0x2a);
 *   case 6: return (*(u8 *)(p+index+0x18)&0x80)>>7;
 *   case 7: return *(u8 *)(p+0x2b);
 *   default:return 0;
 *   }
 * }
 * lever: counter declared before context locals restores stack homes; named selector fixes call-result addition operand order (existing idioms).
 * abi: EE0C retains caller's sixth outgoing word (2), beyond callee's five used arguments.
 */
void func_021DC8EC(char *p,char *q)
{
    u16 record[4];
    int i;
    void *font;
    MsgBank *bank;
    WordSet *words;
    int ready;
    const Descriptor_021DB2E0 *d;
    char *slot;
    U16Vec *text;
    if(!*(int *)(p+0xd4)) {
        *(int *)(p+0xd4)=1;
        if(func_021DD228(*(void **)(p+0xc4))) func_021FB964((void *)(*(int *)(q+0x10)),7,*(u16 *)(p+0xb4));
        else func_021FB964((void *)(*(int *)(q+0x10)),6,*(u16 *)(p+0xb4));
        font=(void *)func_021FC20C(*(char **)(q+0x10));
        bank=(MsgBank *)func_021FC214(*(char **)(q+0x10));
        words=(WordSet *)func_021FC21C(*(char **)(q+0x10));
        for(i=0;i<5;i++) {
            d=&d_021E32C8[i];
            slot=p+i*4;
            *(void **)(slot+0x30)=func_021FC6A4(1,d->x,d->y,d->w,d->h,14,*(void **)(p+4),*(u16 *)(p+0xb4));
            switch(i) {
            case 0:
                {
                void *name;
                void *message;
                text=STRBUF_Create(128,*(u16 *)(p+0xb4));
                name=GDS_PROFILE_CreateNameStr(*(void **)(p+0xc0),*(u16 *)(p+0xb4));
                message=func_02045EC0(bank,d->message);
                func_0201EE0C(words,0,name,func_0200D6EC(*(RecGet **)(p+0xc0)),1,2);
                func_0201F250(words,text,message);
                STRBUF_Delete((U16Vec *)name);STRBUF_Delete((U16Vec *)message);
                func_021FC868(*(void **)(slot+0x30),0,1,0);
                ready=1;break;
                }
            case 1:
                {
                u32 selector;
                selector=BATTLE_REC_GetHeaderParam(*(void **)(p+0xc4),3,0);
                text=func_02045EC0(bank,selector+d->message);
                func_021FC868(*(void **)(slot+0x30),0,1,0);ready=1;break;
                }
            case 2:
                {
                u64 value;
                u64 quotient;
                u32 low,middle,high;
                void *message;
                void *temporary;
                value=BATTLE_REC_GetHeaderParam(*(void **)(p+0xc4),4,0);
                low=value%100000ULL;
                quotient=value/100000ULL;
                middle=quotient%100000ULL;
                high=quotient/100000ULL;
                temporary=func_0200D774(*(GdsProfile **)(p+0xc0),(GdsRecord *)record,*(u16 *)(p+0xb4));
                if(temporary) {
                    message=func_02045EC0(bank,13);STRBUF_Delete((U16Vec *)temporary);
                } else message=func_02045EC0(bank,d->message);
                text=STRBUF_Create(128,*(u16 *)(p+0xb4));
                func_0201EFA4(words,2,low,5,2,1);func_0201EFA4(words,1,middle,5,2,1);func_0201EFA4(words,0,high,2,2,1);
                func_0201F250(words,text,message);
                func_021FC868(*(void **)(slot+0x30),0,1,0);STRBUF_Delete((U16Vec *)message);
                ready=1;break;
                }
            case 3:
                if(func_021DD25C(*(void **)(p+0xc4))) {
                    u32 count;
                    void *message;
                    count=BATTLE_REC_GetHeaderParam(*(void **)(p+0xc4),2,0);
                    text=STRBUF_Create(128,*(u16 *)(p+0xb4));
                    message=func_02045EC0(bank,d->message);
                    func_0201EFA4(words,0,count,4,0,1);func_0201F250(words,text,message);STRBUF_Delete((U16Vec *)message);
                    func_021FC868(*(void **)(slot+0x30),0,1,1);ready=1;
                } else ready=0;
                break;
            case 4:
                if(func_021DD25C(*(void **)(p+0xc4))) {
                    text=func_02045EC0(bank,d->message);
                    func_021FC868(*(void **)(slot+0x30),0,1,1);ready=1;
                } else ready=0;
                break;
            }
            if(ready) {
                func_021FC7C4(*(char **)(slot+0x30),text,font,0x3da0);STRBUF_Delete(text);
            }
        }
        func_021DCBD8(p,*(void **)(q+0x18),*(void **)(p+0xc4),*(u16 *)(p+0xb4));
    }
}










/*
 * note 2026-10-05: re-run, bytes identical to the original; the only unresolved relocation is the BL to arm9 0x0200B98C (Thumb, 64 bytes, no code-start label, no asm/arm9 witness). Integrator: seed a label at 0x0200B98C; no source change needed.
 * blocker-symbols: BattleRecModeTable 0x0209DDCC data a4
 *   typedef unsigned char u8;
 *   typedef unsigned short u16;
 *   typedef unsigned long long u64;
 *   extern const u16 BattleRecModeTable[];
 *   u64 BATTLE_REC_GetHeaderParam(char *p, int selector, int index)
 *   {
 *       int i;
 *       u16 v;
 *       switch (selector) {
 *       case 0:
 *           v = ((u16 *)p)[index];
 *           if (v > 0x289) return 0;
 *           return v;
 *       case 1:
 *           return *(u8 *)(p + index + 0x18) & 0x7F;
 *       case 2:
 *           v = *(u16 *)(p + 0x24);
 *           if (v > 0x270F) return 0x270F;
 *           return v;
 *       case 3:
 *           for (i = 0; i < 0x29; i++) {
 *               if (*(u16 *)(p + 0x26) == BattleRecModeTable[i]) return i;
 *           }
 *           return 0;
 *       case 4:
 *           return *(u64 *)(p + 0x38);
 *       case 5:
 *           return *(u8 *)(p + 0x2A);
 *       case 6:
 *           return (*(u8 *)(p + index + 0x18) & 0x80) >> 7;
 *       case 7:
 *           return *(u8 *)(p + 0x2B);
 *       default:
 *           return 0;
 *       }
 *   }
 * lever: swapped start/end declaration homes, then zeroed phase-two j before coords assignment; DIFF16 to4 to MATCH.
 * checks: 1 own ARM9 and matched caller arities re-derived; B98C original shown, 3 args/u64, DD228 shown 1 arg; 2 F838 and F620/DE084 twins reread; 3 codegen became MATCH in3 runs, further type probes unnecessary; 4 counter-before-base/declared-struct idioms read; 5 fresh directory/neighbors reread before handoff; prior permuter300 not repeated.
 * TU: cbd8-tu.log terminal exit0, MATCH, three B98C wildcards at +009A/+00A6/+00B2, no viable split.
 */
void func_021DCBD8(char *p,void *manager,void *party,u16 heap)
{
    u32 species[12],forms[12],half[12];
    Position pos;
    u32 v,f,h;
    int count=0;
    int mode;
    void *archive;
    int step;
    int i;
    int start;
    int n;
    int end;
    const Point16 *coords;
    char *slot;
    int mapping;
    archive=func_020490F4(7,(u16)((heap&0x7fff)|0x8000));
    *(void **)(p+0x48)=(void *)CLACT_RegisterPaletteCompressed(archive,func_0201BC3C(),0,128,heap);
    mapping=func_0201BC40();
    *(void **)(p+0x4c)=(void *)CLACT_RegisterCellAnim(archive,mapping,func_0201BCB4(),heap);
    n=0;
    step=6;start=0;end=6;mode=0;
    if(func_021DD228(party)==1) {step=3;end=3;mode=1;}
    do {
        for(i=start;i<end;i++) {
            species[n]=255;
            v=BATTLE_REC_GetHeaderParam(party,0,i);
            f=BATTLE_REC_GetHeaderParam(party,1,i);
            h=BATTLE_REC_GetHeaderParam(party,6,i);
            if(v) {species[n]=v;forms[n]=f;half[n]=h;n++;}
        }
        for(i=n;i<end;i++) {species[n]=0;forms[n]=0;half[n]=0;n++;}
        start+=step;end+=step;
    } while(end<=12);
    {
    int j;
    u32 h2,f2,v2;
    j=0;
    coords=(const Point16 *)((u32)d_021E32F0+(int)mode*48);
    for(;j<12;j++) {
        slot=p+j*4;
        *(void **)(slot+0x80)=0;
        *(u32 *)(slot+0x50)=-1;
        v2=species[j];
        if(v2) {
            h2=half[j];f2=forms[j];
            *(u32 *)(slot+0x50)=CLACT_RegisterCharacter(archive,POKE_TOOL_CalcGraphicIndex(v2,f2,h2,0),0,0,heap);
            func_02082BCC(&pos,0,8);
            pos.x=coords[j].x+8;pos.y=coords[j].y-12;pos.z=1;pos.a=12-count;
            *(void **)(p+count*4+0x80)=CLACT_CreateActor(manager,(u32)(*(void **)(slot+0x50)),(u32)(*(void **)(p+0x48)),(u32)(*(void **)(p+0x4c)),&pos,0,heap);
            func_0204B688(*(void **)(count*4+p+0x80),1);
            func_0204B6F4(*(void **)(p+count*4+0x80),func_0201BB5C(v2,f2,h2,0),0);
            count++;
        }
    }
    }
    ARC_TOOL_DeleteHandle(archive);
}










void func_021DCDD8(char *p, char *q)
{
    int flag;
    if(*(int *)(p+0x44)==0 && *(int *)(p+0xdc)==0) {
        *(int *)(p+0xdc)=1;
        flag=1;
        if(*(int *)(*(char **)(p+0xd0)+8)==0) flag=0;
        *(void **)(p+0x44)=func_021FD1C4((void *)(*(int *)(p+0xc0)),(char *)(*(int *)(q+0x10)),(void *)(*(int *)(q+0x18)),(void *)(*(int *)(p+4)),flag,*(unsigned short *)(p+0xb4));
    }
}










void func_021DCE28(char *p,char *unused) { if(((struct CodeinWorkB *)p)->fDC && *(int * *)&((struct CodeinWorkB *)p)->f44) { func_021FD640(*(int * *)&((struct CodeinWorkB *)p)->f44); ((struct CodeinWorkB *)p)->f44=0; ((struct CodeinWorkB *)p)->fDC=0; } }









void func_021DCE48(char *p,char *q)
{
    int i;
    char *slot;
    if(((struct CodeinWorkB *)p)->fD4) {
        for(i=0;i<12;i++) {
            slot=p+i*4;
            if(((struct CodeinWorkC *)slot)->f80) {
                func_0204B3DC(((struct CodeinWorkC *)slot)->f80,0);
                CLACT_DeleteActor(((struct CodeinWorkC *)slot)->f80);
                *(int *)&((struct CodeinWorkC *)slot)->f80=0;
            }
            if(((struct CodeinWorkC *)slot)->f50!=-1) { CLACT_ReleaseCharacter(((struct CodeinWorkC *)slot)->f50); ((struct CodeinWorkC *)slot)->f50=-1; }
        }
        if(((struct CodeinWorkB *)p)->f48!=-1) { CLACT_ReleasePalette(((struct CodeinWorkB *)p)->f48); ((struct CodeinWorkB *)p)->f48=-1; }
        if(((struct CodeinWorkB *)p)->f4C!=-1) { CLACT_ReleaseCellAnim(((struct CodeinWorkB *)p)->f4C); ((struct CodeinWorkB *)p)->f4C=-1; }
        for(i=0;i<5;i++) {
            slot=p+i*4;
            if(((struct CodeinWorkC *)slot)->f30) { func_021FC734(((struct CodeinWorkC *)slot)->f30); *(int *)&((struct CodeinWorkC *)slot)->f30=0; }
        }
        func_021FBDA4(((struct CodeinArgA *)q)->f10,6);
        func_020409B4(1);
        ((struct CodeinWorkB *)p)->fD4=0;
    }
}









void func_021DCEE4(char *p,char *q)
{
    int a,b;
    if(!((struct CodeinWorkA *)p)->fD8) {
        ((struct CodeinWorkA *)p)->fD8=1;
        func_021FB964((void *)(*(int *)&((struct CodeinArgB *)q)->f10),5,((struct CodeinWorkA *)p)->fB4);
        func_021FBE54(*(char * *)&((struct CodeinArgB *)q)->f10,6,((struct CodeinWorkA *)p)->fB4);
        a=func_021FC20C(*(char * *)&((struct CodeinArgB *)q)->f10);
        b=func_021FC214(*(char * *)&((struct CodeinArgB *)q)->f10);
        if(((struct CodeinWorkA *)p)->fCC) {
            Params d;
            Triple t;
            func_02082BCC(&d,0,8);
            d.a=24;d.b=168;d.c=0;d.flag=1;
            func_021FC124(((struct CodeinArgB *)q)->f10,6,&t);
            (*(void * *)&((struct CodeinWorkA *)p)->f1C)=func_021FB378(&d,4,96,1,((struct CodeinArgB *)q)->f18,(*(int *)&((struct CodeinWorkA *)p)->f0),a,b,&t,((struct CodeinWorkA *)p)->fB4);
            d.a=136;d.c=3;
            (*(void * *)&((struct CodeinWorkA *)p)->f20)=func_021FB378(&d,84,96,1,((struct CodeinArgB *)q)->f18,(*(int *)&((struct CodeinWorkA *)p)->f0),a,b,&t,((struct CodeinWorkA *)p)->fB4);
        } else {
            Params d;
            Triple t;
            func_02082BCC(&d,0,8);
            d.a=80;d.b=168;d.c=0;d.flag=1;
            func_021FC124(((struct CodeinArgB *)q)->f10,6,&t);
            (*(void * *)&((struct CodeinWorkA *)p)->f1C)=func_021FB378(&d,4,96,1,((struct CodeinArgB *)q)->f18,(*(int *)&((struct CodeinWorkA *)p)->f0),a,b,&t,((struct CodeinWorkA *)p)->fB4);
        }
        (*(void * *)&((struct CodeinWorkA *)p)->f28)=func_021FC6A4(4,8,3,16,2,14,((struct CodeinWorkA *)p)->f4,((struct CodeinWorkA *)p)->fB4);
        if(((struct CodeinWorkA *)p)->fB0) func_021FC754(((struct CodeinWorkA *)p)->f28,(void *)b,(void *)0x72,(void *)a,0x3da0);
        else func_021FC754(((struct CodeinWorkA *)p)->f28,(void *)b,(void *)0x71,(void *)a,0x3da0);
    }
}









void func_021DD054(char *p, char *q)
{
    int i;
    char *slot;
    if(((struct CodeinWorkB *)p)->fD8) {
        if(((struct CodeinWorkB *)p)->f28) { func_021FC734(((struct CodeinWorkB *)p)->f28); *(int *)&((struct CodeinWorkB *)p)->f28=0; }
        for(i=0;i<2;i++) {
            slot=p+i*4;
            if(((struct CodeinSlotA *)slot)->f1C) { func_021FB494(((struct CodeinSlotA *)slot)->f1C); *(int *)&((struct CodeinSlotA *)slot)->f1C=0; }
        }
        func_020409B4(4);
        func_021FC0C8((char *)(((struct CodeinArgA *)q)->f10),6);
        func_021FBDA4(((struct CodeinArgA *)q)->f10,5);
        ((struct CodeinWorkB *)p)->fD8=0;
    }
}







void func_021DD0AC(char *p, char *unused)
{
    if (!((struct CodeinWorkB *)p)->fE0) {
        Point args;
        ((struct CodeinWorkB *)p)->fE0 = 1;
        if (!((struct CodeinWorkB *)p)->f18)
            ((struct CodeinWorkB *)p)->f18 = func_021FD12C(((struct CodeinSubA *)(((struct CodeinWorkB *)p)->fD0))->f10, (void *)(((struct CodeinWorkB *)p)->f4), ((struct CodeinWorkB *)p)->fB4);
        args.x = 0x80;
        args.y = 0x60;
        func_021FD860((void *)(((struct CodeinWorkB *)p)->fC), 4, &args);
    }
}







void func_021DD0F4(char *p, char *a1) { if(((struct CodeinWorkB *)p)->fE0) { func_021FD860(*(char * *)&((struct CodeinWorkB *)p)->fC,0,0); if(((struct CodeinWorkB *)p)->f18) { func_021FD15C(((struct CodeinWorkB *)p)->f18,((struct CodeinSubA *)(((struct CodeinWorkB *)p)->fD0))->f10); *(int *)&((struct CodeinWorkB *)p)->f18=0; } ((struct CodeinWorkB *)p)->fE0=0; } }







void func_021DD128(char *p, char *q)
{
    if (!((struct CodeinWorkB *)p)->fE4) {
        int first, second, i;
        const Record *rec;
        char *slot;
        ((struct CodeinWorkB *)p)->fE4 = 1;
        if (!((struct CodeinWorkB *)p)->f18)
            ((struct CodeinWorkB *)p)->f18 = func_021FD12C(((struct CodeinArgA *)q)->f10, (void *)(((struct CodeinWorkB *)p)->f4), ((struct CodeinWorkB *)p)->fB4);
        func_021FD170(((struct CodeinWorkB *)p)->f18, (char *)(((struct CodeinArgA *)q)->f10), (void *)0x14f);
        func_021FB964((void *)(((struct CodeinArgA *)q)->f10), 30, ((struct CodeinWorkB *)p)->fB4);
        first = func_021FC20C(*(char * *)&((struct CodeinArgA *)q)->f10);
        second = func_021FC214(*(char * *)&((struct CodeinArgA *)q)->f10);
        for (i = 0; i < 2; i++) {
            rec = &d_021E32A8[i];
            slot = p + i * 4;
            ((struct CodeinWorkC *)slot)->f28 = func_021FC6A4(4, rec->a, rec->b, rec->c, rec->d, 14, (void *)(((struct CodeinWorkB *)p)->f4), ((struct CodeinWorkB *)p)->fB4);
            func_021FC754(((struct CodeinWorkC *)slot)->f28, (void *)second, (void *)rec->value, (void *)first, 0x3da0);
        }
    }
}












/*
 * trailing: 2 zero alignment bytes at 0x021DD226
 */
void func_021DD1D4(char *p, char *q)
{
    int i;
    char *slot;
    if (((struct CodeinWorkB *)p)->fE4) {
        for (i = 0; i < 2; i++) {
            slot = p + i * 4;
            if (((struct CodeinWorkC *)slot)->f28) {
                func_021FC734(((struct CodeinWorkC *)slot)->f28);
                *(int *)&((struct CodeinWorkC *)slot)->f28 = 0;
            }
        }
        func_020409B4(4);
        func_021FBDA4(((struct CodeinArgA *)q)->f10, 30);
        if (((struct CodeinWorkB *)p)->f18) {
            func_021FD15C(((struct CodeinWorkB *)p)->f18, ((struct CodeinArgA *)q)->f10);
            *(int *)&((struct CodeinWorkB *)p)->f18 = 0;
        }
        ((struct CodeinWorkB *)p)->fE4 = 0;
    }
}












/*
 * 2026-10-05 (D8 lane19): re-verified, status unchanged; sole blocker is arm9 callee 0x0200B98C (no witness outside the caller). Needs a label seed. Source is byte-correct; no C change possible.
 * blocker-symbols: BattleRecModeTable 0x0209DDCC data a4
 *   typedef unsigned char u8;
 *   typedef unsigned short u16;
 *   typedef unsigned long long u64;
 *   extern const u16 BattleRecModeTable[];
 *   u64 BATTLE_REC_GetHeaderParam(char *p, int selector, int index)
 *   {
 *       int i;
 *       u16 v;
 *       switch (selector) {
 *       case 0:
 *           v = ((u16 *)p)[index];
 *           if (v > 0x289) return 0;
 *           return v;
 *       case 1: return *(u8 *)(p + index + 0x18) & 0x7F;
 *       case 2:
 *           v = *(u16 *)(p + 0x24);
 *           if (v > 0x270F) return 0x270F;
 *           return v;
 *       case 3:
 *           for (i = 0; i < 0x29; i++) {
 *               if (*(u16 *)(p + 0x26) == BattleRecModeTable[i]) return i;
 *           }
 *           return 0;
 *       case 4: return *(u64 *)(p + 0x38);
 *       case 5: return *(u8 *)(p + 0x2A);
 *       case 6: return (*(u8 *)(p + index + 0x18) & 0x80) >> 7;
 *       case 7: return *(u8 *)(p + 0x2B);
 *       default: return 0;
 *       }
 *   }
 */
int func_021DD228(void *p) { switch((int)BATTLE_REC_GetHeaderParam(p,3,0)) { case 16: case 17: case 18: case 19: case 22: return 1; case 20: case 21: default: return 0; } }












int func_021DD25C(void *p) { int result; int v; result=0; v=(int)BATTLE_REC_GetHeaderParam(p,3,0); if(v==20) goto yes; if(v==21) goto yes; if(v!=22) goto no; yes: return 1; no: return result; }












int func_021DD27C(char *p, int a, int b)
{
    int ok = ((unsigned int)(a - 0x40) <= 0x88) &
             ((unsigned int)(b - 0x10) <= 0x20);
    if (ok) {
        Point args;
        args.x = a;
        args.y = b;
        func_021FD860((void *)((*(int *)&((struct CodeinWorkA *)p)->f10)), 1, &args);
        func_020061E4(0x703);
    }
    return ok;
}












int func_021DD2BC(char *p, int a, int b)
{
    int ok = ((unsigned int)(a - 0x50) <= 0x60) &
             ((unsigned int)(b - 0x38) <= 0x40);
    if (ok) {
        Point args;
        args.x = a;
        args.y = b;
        func_021FD860((void *)((*(int *)&((struct CodeinWorkA *)p)->f10)), 1, &args);
        func_020061E4(0x703);
    }
    return ok;
}












int func_021DD2FC(char *p, int a, int b)
{
    int ok = ((unsigned int)(a - 0x20) <= 0x48) &
             ((unsigned int)(b - 0x30) <= 0x10);
    if (ok) {
        Point args;
        args.x = a;
        args.y = b;
        func_021FD860((void *)(((struct CodeinWorkB *)p)->f10), 1, &args);
        func_020061E4(0x703);
    }
    return ok;
}












int func_021DD33C(char *p, int a, int b)
{
    int ok = ((unsigned int)(a - 0x90) <= 0x48) &
             ((unsigned int)(b - 0x30) <= 0x10);
    if (ok) {
        Point args;
        args.x = a;
        args.y = b;
        func_021FD860((void *)(((struct CodeinWorkB *)p)->f10), 1, &args);
        func_020061E4(0x703);
    }
    return ok;
}












/*
 * trailing: 2 zero alignment bytes at 0x021DD3F6
 */
int func_021DD37C(void *a, int unused, char *q)
{
    struct CodeinWorkA *p = PROCSYS_AllocProcWork(a, 0x80, func_021F9B9C((struct Obj24810 *)(*(char * *)&((struct CodeinArgA *)q)->fC)));
    func_02082BCC(p, 0, 0x80);
    p->f7C = func_021F9B9C((struct Obj24810 *)(*(char * *)&((struct CodeinArgA *)q)->fC));
    p->f0 = BMP_OAM_CreateSys(p->f7C, (*(void * *)&((struct CodeinArgA *)q)->f4));
    p->f4 = (void *)func_0201C440((void *)(p->f7C));
    p->f74 = func_021FD760((unsigned int)((*(void * *)&((struct CodeinArgA *)q)->f4)), (char *)(((struct CodeinArgA *)q)->f8), 1, p->f7C);
    func_021FBE54(*(char * *)&((struct CodeinArgA *)q)->f8, 13, p->f7C);
    func_021DDE2C(p, q);
    func_021DD5C8(p, q);
    return 1;
}











int func_021DD3F8(struct S020315D4 *a, int unused, char *q, char *p)
{
    func_021DDF5C(p, q);
    func_021DDDE8(p, q);
    func_020409B4(4);
    func_020409B4(1);
    func_021FC0C8((char *)(((struct CodeinArgA *)q)->f8), 13);
    func_021FD820(*(char * *)&((struct CodeinWorkA *)p)->f74);
    func_0201C4C0(((struct CodeinWorkA *)p)->f4);
    BMP_OAM_DeleteSys(((struct CodeinWorkA *)p)->f0);
    func_020315D4(a);
    return 1;
}











/*
 * tail: 021DD5C6..021DD5C8 is two zero alignment bytes.
 */
int func_021DD440(void *unused,u32 *state,char *q,char *p)
{
 int x,y,i;
 Point pair;
 switch(*state){
 case 0:func_021FE784(((struct CodeinArgA *)q)->f0,2,3,0);*state=1;break;
 case 1:if(func_021FE7B0(*(int * *)&((struct CodeinArgA *)q)->f0)) *state=2;break;
 case 2:
  if(func_02035D20((u32 *)(&x),(u32 *)(&y))){
   ((struct CodeinWorkA *)p)->f78=func_021DDFA0(p,x,y);
   if(((struct CodeinWorkA *)p)->f78) *state=3;
   if(func_021FB4B4((unsigned int *)((*(int *)&((struct CodeinWorkA *)p)->f20)),x,y)){
    pair.x=x;pair.y=y;
    func_021FD860((void *)(*(int *)&((struct CodeinWorkA *)p)->f74), 1, &pair);
    *state=7;
   }
  }break;
 case 3:func_021FE784(((struct CodeinArgA *)q)->f0,2,1,1);++*state;break;
 case 4:if(func_021FE7B0(*(int * *)&((struct CodeinArgA *)q)->f0)) ++*state;break;
 case 5:
  func_021DDDE8(p,q);
  switch(*(u32 *)&((struct CodeinWorkA *)p)->f78){
  case 1:func_021DD684(p,q);break;
  case 2:func_021DD858(p,q);break;
  case 3:func_021DDA2C(p,q);break;
  case 4:func_021DDCCC(p,q);break;
  }
  func_021FE784(((struct CodeinArgA *)q)->f0,2,1,0);++*state;break;
 case 6:if(func_021FE7B0(*(int * *)&((struct CodeinArgA *)q)->f0)) *state=2;break;
 case 7:func_021FE784(((struct CodeinArgA *)q)->f0,2,3,1);*state=8;break;
 case 8:if(func_021FE7B0(*(int * *)&((struct CodeinArgA *)q)->f0)) *state=9;break;
 case 9:func_021F9BA0(((struct CodeinArgA *)q)->fC);return 1;
 }
 for(i=0;i<4;i++) if(*(void **)(p+i*4+0x24)) func_021FC830(*(void **)(p+i*4+0x24));
 for(i=0;i<16;i++) if(*(void **)(p+i*4+0x34)) func_021FC830(*(void **)(p+i*4+0x34));
 PRINTSYS_QUE_Main(((struct CodeinWorkA *)p)->f4);
 if((*(void * *)&((struct CodeinWorkA *)p)->f1C))func_021FD1BC((*(void * *)&((struct CodeinWorkA *)p)->f1C));
 func_021FD854(((struct CodeinWorkA *)p)->f74);
 return 0;
}











/*
 * lever: const record array at the table address restores early argument loads;
 *        a scalar record and const pointer local remained 22 bytes DIFF.
 */
void func_021DD5C8(struct CodeinWorkA *p, char *q)
{
    int first, second, v;
    Triple triple;
    const Record *rec;
    u8 a, b, c, d;
    first = func_021FC20C(*(char * *)&((struct CodeinArgA *)q)->f8);
    second = func_021FC214(*(char * *)&((struct CodeinArgA *)q)->f8);
    func_021FB964((void *)(((struct CodeinArgA *)q)->f8), 14, p->f7C);
    rec = &d_021E3350[0];
    d = rec->d;
    a = rec->a;
    b = rec->b;
    c = rec->c;
    p->f34 = func_021FC6A4(1, a, b, c, d, 14, p->f4, p->f7C);
    func_021FC868(p->f34, 0, 1, 0);
    func_021FC754(p->f34, (void *)second, (void *)rec->value, (void *)first, 0x3da0);
    (*(void * *)&p->f1C) = func_021FD12C(((struct CodeinArgA *)q)->f8, (void *)(*(int *)&p->f4), p->f7C);
    func_021FD170((*(void * *)&p->f1C), (char *)(((struct CodeinArgA *)q)->f8), (void *)0x86);
    v = func_0200DABC((struct Blk1AC *)(((struct CodeinArgA *)q)->f10));
    func_021FC124((void *)(((struct CodeinArgA *)q)->f8), 13, (Triple *)((Triple *)&triple));
    func_021DE084((void *)((char *)p + 8), (void *)(((struct CodeinArgA *)q)->f4), (const char *)(&triple), v, 0x68, 0x58, p->f7C);
}










void func_021DD684(char *p,char *q)
{
 int first,second,third,index,v;
 const Record *rec;
 char *slot;
 unsigned select;
 int number1,number2;
 void *obj;
 Triple triple;
 first=func_021FC20C(*(char **)(q+8));
 second=func_021FC214(*(char **)(q+8));
 third=func_021FC21C(*(char **)(q+8));
 func_021FB964((void *)(*(int *)(q+8)),10,*(u16 *)(p+0x7c));
 select=func_021DE000((void *)(*(int *)(q+0x10)),(char *)(*(int *)(q+0x14)))?5:0;
 for(index=0;index<8;index++){
  rec=&d_021E33C0[index];slot=p+index*4;
  *(void **)(slot+0x34)=func_021FC6A4(1,rec->a,rec->b,rec->c,rec->d,14,*(void **)(p+4),*(u16 *)(p+0x7c));
  func_021FC868(*(void **)(slot+0x34),0,1,0);
  switch(index){
   case 1:
    obj=func_02045EC0((struct MsgBank *)second,func_021DE000((void *)(*(int *)(q+0x10)),(char *)(*(int *)(q+0x14)))?0x83:0x7e);break;
   case 2:
    obj=func_02045EC0((struct MsgBank *)second,func_0200DB44(*(void **)(q+0x10),select)?0x91:0x87);break;
   case 3:{
    void *base;
    number1=func_0200DAC4(*(void **)(q+0x10),select);
    number1=(number1>9999)?9999:number1;
    base=func_02045EC0((struct MsgBank *)second,rec->value);
    obj=STRBUF_Create(0x80,*(u16 *)(p+0x7c));
    func_0201EFA4((void *)third,0,number1,4,1,1);
    func_0201F250((void *)third,obj,base);
    STRBUF_Delete(base);break;
   }
   case 6:{
    void *base;
    number2=func_0200DAD8(*(void **)(q+0x10),select);
    number2=(number2>9999)?9999:number2;
    base=func_02045EC0((struct MsgBank *)second,rec->value);
    obj=STRBUF_Create(0x80,*(u16 *)(p+0x7c));
    func_0201EFA4((void *)third,0,number2,4,1,1);
    func_0201F250((void *)third,obj,base);
    STRBUF_Delete(base);break;
   }
   default:obj=func_02045EC0((struct MsgBank *)second,rec->value);break;
  }
  func_021FC7C4(*(char **)(slot+0x34),obj,(void *)first,0x3da0);
  STRBUF_Delete(obj);
 }
 v=func_0200DABC(*(void **)(q+0x10));
 func_021FC124((void *)(*(int *)(q+8)), 13, (Triple *)((Triple *)&triple));
 func_021DE084(p+8,*(void **)(q+4),(const char *)&triple,v,0xa0,0x20,*(u16 *)(p+0x7c));
}










/*
 * note: 2026-10-05 wave P10 lane Y1. Twin of func_021DD684 (same body: other table d_021E3400, getter func_021DE02C, selector 6/1, argument 11, strings 0x84/0x7f). 468 B; the 1140 B listing extent also holds func_021DDA2C, filed separately. The clamps are n = (n > 9999) ? 9999 : n; as in the twin.
 */
void func_021DD858(char *p,char *q)
{
 int first,second,third,index,v;
 const Record *rec;
 char *slot;
 unsigned select;
 int number1,number2;
 void *obj;
 Triple triple;
 first=func_021FC20C(*(char **)(q+8));
 second=func_021FC214(*(char **)(q+8));
 third=func_021FC21C(*(char **)(q+8));
 func_021FB964((void *)(*(int *)(q+8)),11,*(u16 *)(p+0x7c));
 select=func_021DE02C((void *)(*(int *)(q+0x10)),(void *)(*(int *)(q+0x14)))?6:1;
 for(index=0;index<8;index++){
  rec=&d_021E3400[index];slot=p+index*4;
  *(void **)(slot+0x34)=func_021FC6A4(1,rec->a,rec->b,rec->c,rec->d,14,*(void **)(p+4),*(u16 *)(p+0x7c));
  func_021FC868(*(void **)(slot+0x34),0,1,0);
  switch(index){
   case 1:
    obj=func_02045EC0((struct MsgBank *)second,func_021DE02C((void *)(*(int *)(q+0x10)),(void *)(*(int *)(q+0x14)))?0x84:0x7f);break;
   case 2:
    obj=func_02045EC0((struct MsgBank *)second,func_0200DB44(*(void **)(q+0x10),select)?0x91:0x87);break;
   case 3:{
    void *base;
    number1=func_0200DAC4(*(void **)(q+0x10),select);
    number1=(number1>9999)?9999:number1;
    base=func_02045EC0((struct MsgBank *)second,rec->value);
    obj=STRBUF_Create(0x80,*(u16 *)(p+0x7c));
    func_0201EFA4((void *)third,0,number1,4,1,1);
    func_0201F250((void *)third,obj,base);
    STRBUF_Delete(base);break;
   }
   case 6:{
    void *base;
    number2=func_0200DAD8(*(void **)(q+0x10),select);
    number2=(number2>9999)?9999:number2;
    base=func_02045EC0((struct MsgBank *)second,rec->value);
    obj=STRBUF_Create(0x80,*(u16 *)(p+0x7c));
    func_0201EFA4((void *)third,0,number2,4,1,1);
    func_0201F250((void *)third,obj,base);
    STRBUF_Delete(base);break;
   }
   default:obj=func_02045EC0((struct MsgBank *)second,rec->value);break;
  }
  func_021FC7C4(*(char **)(slot+0x34),obj,(void *)first,0x3da0);
  STRBUF_Delete(obj);
 }
 v=func_0200DABC(*(void **)(q+0x10));
 func_021FC124((void *)(*(int *)(q+8)), 13, (Triple *)((Triple *)&triple));
 func_021DE084(p+8,*(void **)(q+4),(const char *)&triple,v,0xa0,0x20,*(u16 *)(p+0x7c));
}








/*
 * lever: bounded permuter rec/index declaration order, selector use and
 *        field-base expansion restore the three selector/index spill homes.
 */
void func_021DDA2C(char *p, char *q)
{
  int first;
  int second;
  int third;
  const Record *rec;
  int v;
  unsigned select;
  unsigned select2;
  int index;
  char *slot;
  int number1;
  int number2;
  int number3;
  int number4;
  void *obj;
  Triple triple;
  char **tmp1;
  u16 tmp;
  first = func_021FC20C(*((char **) (q + 8)));
  second = func_021FC214(*((char **) (q + 8)));
  third = func_021FC21C(*((char **) (q + 8)));
  tmp = *((u16 *) (p + 0x7c));
  func_021FB964((void *)(*((int *) (q + 8))), 12, tmp);
  if (func_021DE058((void *)(*((int *) (q + 0x10))), (void *)(*((int *) (q + 0x14)))))
  {
    select = 7;
    select2 = 8;
  }
  else
  {
    select = 2;
    select2 = 3;
  }
  ;
  for (index = 0; index < 16; index++)
  {
    rec = &d_021E3490[index];
    slot = p + (index * 4);
    *((void **) (slot + 0x34)) = func_021FC6A4(1, (&d_021E3490[index])->a, (&d_021E3490[index])->b, (&d_021E3490[index])->c, (&d_021E3490[index])->d, 14, *((void **) (p + 4)), *((u16 *) (p + 0x7c)));
    func_021FC868(*((void **) (slot + 0x34)), 0, 1, 0);
    switch (index)
    {
      if (select2)
      {
      }
      case 1:
        obj = func_02045EC0((struct MsgBank *)second, (func_021DE058((void *)(*((int *) (q + 0x10))), (void *)(*((int *) (q + 0x14))))) ? (0x85) : (0x80));
        break;

      case 3:
        obj = func_02045EC0((struct MsgBank *)second, (func_0200DB44(*((void **) (q + 0x10)), select)) ? (0x91) : (0x87));
        break;

      case 4:
      {
        void *base;
        number1 = func_0200DAC4(*((void **) (q + 0x10)), select);
        if (number1 > 9999)
          number1 = 9999;
        base = func_02045EC0((struct MsgBank *)second, rec->value);
        obj = STRBUF_Create(0x80, *((u16 *) (p + 0x7c)));
        func_0201EFA4((void *) third, 0, number1, 4, 1, 1);
        func_0201F250((void *) third, obj, base);
        STRBUF_Delete(base);
        break;
      }

      case 7:
      {
        void *base;
        number2 = func_0200DAD8(*((void **) (q + 0x10)), select);
        if (number2 > 9999)
          number2 = 9999;
        base = func_02045EC0((struct MsgBank *)second, rec->value);
        obj = STRBUF_Create(0x80, *((u16 *) (p + 0x7c)));
        func_0201EFA4((void *) third, 0, number2, 4, 1, 1);
        func_0201F250((void *) third, obj, base);
        STRBUF_Delete(base);
        break;
      }

      case 10:
        obj = func_02045EC0((struct MsgBank *)second, (func_0200DB44(*((void **) (q + 0x10)), select2)) ? (0x91) : (0x87));
        break;

      case 11:
      {
        void *base;
        number3 = func_0200DAC4(*((void **) (q + 0x10)), select2);
        if (number3 > 9999)
          number3 = 9999;
        base = func_02045EC0((struct MsgBank *)second, rec->value);
        obj = STRBUF_Create(0x80, *((u16 *) (p + 0x7c)));
        func_0201EFA4((void *) third, 0, number3, 4, 1, 1);
        func_0201F250((void *) third, obj, base);
        STRBUF_Delete(base);
        break;
      }

      case 14:
      {
        void *base;
        number4 = func_0200DAD8(*((void **) (q + 0x10)), select2);
        if (number4 > 9999)
          number4 = 9999;
        base = func_02045EC0((struct MsgBank *)second, rec->value);
        obj = STRBUF_Create(0x80, *((u16 *) (p + 0x7c)));
        func_0201EFA4((void *) third, 0, number4, 4, 1, 1);
        func_0201F250((void *) third, obj, base);
        STRBUF_Delete(base);
        break;
      }

      default:
        obj = func_02045EC0((struct MsgBank *)second, rec->value);
        break;

    }

    tmp1 = (char **) (slot + 0x34);
    func_021FC7C4(*tmp1, obj, (void *) first, 0x3da0);
    STRBUF_Delete(obj);
  }

  v = func_0200DABC((struct Blk1AC *)(*((int *) (q + 0x10))));
  func_021FC124((void *)(*((int *) (q + 8))), 13, (Triple *)((Triple *)&triple));
  func_021DE084(p + 8, *((void **) (q + 4)), (const char *) (&triple), v, 0xa0, 0x20, *((u16 *) (p + 0x7c)));
}








/*
 * lever: declaring the text object before the loop index fixes r4/r5.
 */
void func_021DDCCC(char *p,char *q)
{
 int first,second,third,v,text;
 void *obj;
 int i;
 char *slot;
 const Record *rec;
 Triple triple;
 first=func_021FC20C(*(char * *)&((struct CodeinArgA *)q)->f8);
 second=func_021FC214(*(char * *)&((struct CodeinArgA *)q)->f8);
 third=func_021FC21C(*(char * *)&((struct CodeinArgA *)q)->f8);
 func_021FB964((void *)(((struct CodeinArgA *)q)->f8),13,((struct CodeinWorkA *)p)->f7C);
 for(i=0;i<5;i++){
  rec=&d_021E338C[i]; slot=p+i*4;
  ((struct CodeinWorkC *)slot)->f34=func_021FC6A4(1,rec->a,rec->b,rec->c,rec->d,14,((struct CodeinWorkA *)p)->f4,((struct CodeinWorkA *)p)->f7C);
  if(i==4){
   v=func_0200DC08((struct Blk1AC *)(((struct CodeinArgA *)q)->f10));
   text=(int)func_02045EC0((struct MsgBank *)second,rec->value);
   obj=STRBUF_Create(0x80,((struct CodeinWorkA *)p)->f7C);
   func_0201EFA4((void *)third,0,v,2,1,1);
   func_0201F250((void *)third,obj,(void *)text);
   STRBUF_Delete((struct U16Vec *)text);
  }else obj=(void *)func_02045EC0((struct MsgBank *)second,rec->value);
  func_021FC7C4(*(char * *)&((struct CodeinWorkC *)slot)->f34,obj,(void *)first,0x3da0);
  STRBUF_Delete((struct U16Vec *)((int)obj));
 }
 v=func_0200DABC((struct Blk1AC *)(((struct CodeinArgA *)q)->f10));
 func_021FC124((void *)(((struct CodeinArgA *)q)->f8), 13, (Triple *)((Triple *)&triple));
 func_021DE084(p+8,(*(void * *)&((struct CodeinArgA *)q)->f4),(const char *)&triple,v,0xa0,0x20,((struct CodeinWorkA *)p)->f7C);
}








void func_021DDDE8(char *p, char *q)
{
    int i;
    char *slot;
    func_021DE12C(p + 8);
    for (i = 0; i < 16; i++) {
        slot = p + i * 4;
        if (((struct CodeinWorkC *)slot)->f34) {
            func_021FC734(((struct CodeinWorkC *)slot)->f34);
            *(int *)&((struct CodeinWorkC *)slot)->f34 = 0;
        }
    }
    func_021FBDA4(((struct CodeinArgA *)q)->f8, 10);
    if ((*(void * *)&((struct CodeinWorkA *)p)->f1C)) {
        func_021FD15C((*(void * *)&((struct CodeinWorkA *)p)->f1C), ((struct CodeinArgA *)q)->f8);
        *(int *)&((struct CodeinWorkA *)p)->f1C = 0;
    }
}







void func_021DDE2C(struct CodeinWorkA *p,char *q)
{
 int first,second,i,id;
 Triple triple;
 Position pos;
 const Record *rec;
 char *slot;
 func_021FBE54(*(char * *)&((struct CodeinArgA *)q)->f8,6,p->f7C);
 func_021FB964((void *)(((struct CodeinArgA *)q)->f8),9,p->f7C);
 first=func_021FC20C(*(char * *)&((struct CodeinArgA *)q)->f8);
 second=func_021FC214(*(char * *)&((struct CodeinArgA *)q)->f8);
 func_02082BCC(&pos,0,8);
 pos.x=0x50;pos.y=0xa8;pos.z=0;pos.a=1;
 func_021FC124((void *)(((struct CodeinArgA *)q)->f8), 6, (Triple *)((Triple *)&triple));
 (*(void * *)&p->f20)=func_021FB378(&pos,4,0x60,1,((struct CodeinArgA *)q)->f4,*(int *)&p->f0,first,second,&triple,p->f7C);
 for(i=0;i<4;i++){
  rec=&d_021E336C[i];slot=(char *)p+i*4;
  (*(void * *)&((struct CodeinWorkC *)slot)->f24)=func_021FC6A4(4,rec->a,rec->b,rec->c,rec->d,14,p->f4,p->f7C);
  switch(i){
   case 0: if(func_021DE000((void *)(((struct CodeinArgA *)q)->f10),(char *)(((struct CodeinArgA *)q)->f14))) id=0x83;else id=0x7e;break;
   case 1: if(func_021DE02C((void *)(((struct CodeinArgA *)q)->f10),(void *)(((struct CodeinArgA *)q)->f14))) id=0x84;else id=0x7f;break;
   case 2: if(func_021DE058((void *)(((struct CodeinArgA *)q)->f10),(void *)(((struct CodeinArgA *)q)->f14))) id=0x85;else id=0x80;break;
   case 3: id=0x81;break;
  }
  func_021FC754((*(void * *)&((struct CodeinWorkC *)slot)->f24),(void *)second,(void *)id,(void *)first,0x3da0);
 }
}







void func_021DDF5C(char *p, char *q)
{
    int i;
    char *slot;
    for (i = 0; i < 4; i++) {
        slot = p + i * 4;
        if ((*(void * *)&((struct CodeinWorkC *)slot)->f24)) {
            func_021FC734((*(void * *)&((struct CodeinWorkC *)slot)->f24));
            *(int *)&((struct CodeinWorkC *)slot)->f24 = 0;
        }
    }
    if ((*(void * *)&((struct CodeinWorkA *)p)->f20)) {
        func_021FB494((*(void * *)&((struct CodeinWorkA *)p)->f20));
        *(int *)&((struct CodeinWorkA *)p)->f20 = 0;
    }
    func_021FC0C8((char *)(((struct CodeinArgA *)q)->f8), 6);
    func_021FBDA4(((struct CodeinArgA *)q)->f8, 9);
}







int func_021DDFA0(char *p, int x, int y)
{
    int skip = ((struct CodeinWorkA *)p)->f78;
    int i;
    for (i = 0; i < 5; i++) {
        if (i != skip && (u32)(x - d_021E3440[i].x0) <= d_021E3440[i].x1 - d_021E3440[i].x0 &&
            (u32)(y - d_021E3440[i].y0) <= d_021E3440[i].y1 - d_021E3440[i].y0) {
            Point args;
            args.x = x;
            args.y = y;
            func_021FD860((void *)(*(int *)&((struct CodeinWorkA *)p)->f74), 1, &args);
            func_020061E4(0x703);
            return i;
        }
    }
    return 0;
}







int func_021DE000(void *p,char *q) { u32 a,b; a=func_0200DBA0(p,4,0); b=ZONEDATA_CheckEventFlag((void *)func_0201296C((const struct BigObj *)q),0x960); if(a && b) return 1; return 0; }







int func_021DE02C(void *p, void *q)
{
    int a = func_0200DBA0(p, 5, 0);
    unsigned b = ZONEDATA_CheckEventFlag((void *)func_0201296C(q), 0x960);
    if (a && b) return 1;
    return 0;
}







int func_021DE058(void *p, void *q)
{
    int a = func_0200DBA0(p, 6, 0);
    unsigned b = ZONEDATA_CheckEventFlag((void *)func_0201296C(q), 0x960);
    if (a && b) return 1;
    return 0;
}









/*
 * extent: two trailing zero bytes are alignment padding before the next labelled function.
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`base = x;` before `base = x + 20;`). Game code has no line table, so
 * these were stand-ins. The plain single assignment gives EXACT* in --lang
 * c99 and --lang c: the output bytes do not change. Older text in this
 * header that asks for the double assignment is superseded.
 */
void func_021DE084(char *p, void *manager, const char *q, unsigned int value, s16 x, s16 y, u16 heap)
{
    Position pos;
    int base;
    int i;
    func_02082BCC(p, 0, 0x14);
    func_02082BCC(&pos, 0, 8);
    pos.x = x;
    pos.y = y;
    pos.z = 10;
    ((struct CodeinWorkA *)p)->f0 = CLACT_CreateActor(manager, (unsigned int)(*(void * *)&((struct CodeinArgA *)q)->f4), (unsigned int)(*(void * *)&((struct CodeinArgA *)q)->f8), (unsigned int)(*(void * *)&((struct CodeinArgA *)q)->f0), &pos, 0, heap);
    func_0204B688(((struct CodeinWorkA *)p)->f0, 1);
    pos.z = 0;
    base = x + 20;
    for (i = 0; i < 4; i++) {
        char *slot;
        pos.x = base + i * 16;
        pos.y = y;
        slot = p + i * 4;
        ((struct CodeinWorkC *)slot)->f4 = CLACT_CreateActor(manager, (unsigned int)(*(void * *)&((struct CodeinArgA *)q)->f4), (unsigned int)(*(void * *)&((struct CodeinArgA *)q)->f8), (unsigned int)(*(void * *)&((struct CodeinArgA *)q)->f0), &pos, 0, heap);
        func_0204B688(((struct CodeinWorkC *)slot)->f4, 1);
    }
    func_021DE15C(p, value);
}









void func_021DE12C(char *p)
{
    int i;
    for (i = 0; i < 4; i++) {
        char *slot = p + i * 4;
        if (((struct CodeinWorkC *)slot)->f4) {
            CLACT_DeleteActor(((struct CodeinWorkC *)slot)->f4);
            ((struct CodeinWorkC *)slot)->f4 = 0;
        }
    }
    CLACT_DeleteActor(((struct CodeinWorkA *)p)->f0);
    func_02082BCC(p, 0, 20);
}









void func_021DE15C(char *p, u32 value)
{
    u8 temp = value;
    int i;
    int j;
    if (temp != 0) {
        for (;;) {
            if (temp == 0) break;
            temp /= 10;
        }
    }
    for (i = 0; i < 4; i++) CLACT_SetActorAnimSeq(*(void **)(p + i * 4 + 4), 0);
    for (j = 0; j < 4; j++)
        CLACT_SetActorAnimSeq(*(void **)(p + (3 - j) * 4 + 4), value % d_021E3358[j + 1] / d_021E3358[j]);
}









int func_021DE1C8(void *a, int b, char *q)
{
    char *p = PROCSYS_AllocProcWork(a, 0x70, func_021F9B9C(((struct CodeinArgA *)q)->fC));
    func_02082BCC(p, 0, 0x70);
    ((struct CodeinWorkA *)p)->f6C = func_021F9B9C(((struct CodeinArgA *)q)->fC);
    ((struct CodeinWorkA *)p)->f0 = BMP_OAM_CreateSys(((struct CodeinWorkA *)p)->f6C, (*(void * *)&((struct CodeinArgA *)q)->f0));
    ((struct CodeinWorkA *)p)->f4 = (void *)func_0201C440((void *)(((struct CodeinWorkA *)p)->f6C));
    ((struct CodeinWorkA *)p)->f64 = func_021FD760((unsigned int)((*(void * *)&((struct CodeinArgA *)q)->f0)), (char *)(((struct CodeinArgA *)q)->f8), 1, ((struct CodeinWorkA *)p)->f6C);
    func_021DE3E4(p, q);
    func_021DE7C0(p, q);
    return 1;
}









int func_021DE234(void *a, int b, char *q, struct CodeinWorkA *p)
{
    func_021DE780(p, q);
    func_021DE8FC(p, q);
    func_020409B4(4);
    func_020409B4(1);
    func_021FD820(p->f64);
    func_0201C4C0(p->f4);
    BMP_OAM_DeleteSys(p->f0);
    func_020315D4(a);
    return 1;
}









int func_021DE274(void *unused,u32 *state,char *q,struct CodeinWorkA *p)
{
 int x,y,i;
 Point pair;
 switch(*state){
 case 0:func_021FE784(((struct CodeinArgA *)q)->f4,2,3,0);*state=1;break;
 case 1:if(func_021FE7B0(*(int * *)&((struct CodeinArgA *)q)->f4)) *state=2;break;
 case 2:
  if(func_02035D20((u32 *)(&x),(u32 *)(&y))){
   p->f68=func_021DE940(p,x,y);
   if(p->f68) *state=3;
   if(func_021FB4B4((unsigned int *)((*(int *)&p->fC)),x,y)){
    pair.x=x;pair.y=y;
    func_021FD860((void *)(*(int *)&p->f64), 1, &pair);
    *state=7;
   }
  }break;
 case 3:func_021FE784(((struct CodeinArgA *)q)->f4,2,1,1);++*state;break;
 case 4:if(func_021FE7B0(*(int * *)&((struct CodeinArgA *)q)->f4)) ++*state;break;
 case 5:
  func_021DE780(p,q);
  switch(*(u32 *)&p->f68){
  case 1:func_021DE404(p,q);break;
  case 2:func_021DE55C(p,q);break;
  case 3:func_021DE66C(p,q);break;
  }
  func_021FE784(((struct CodeinArgA *)q)->f4,2,1,0);++*state;break;
 case 6:if(func_021FE7B0(*(int * *)&((struct CodeinArgA *)q)->f4)) *state=2;break;
 case 7:func_021FE784(((struct CodeinArgA *)q)->f4,2,3,1);*state=8;break;
 case 8:if(func_021FE7B0(*(int * *)&((struct CodeinArgA *)q)->f4)) *state=9;break;
 case 9:func_021F9BA0(((struct CodeinArgA *)q)->fC);return 1;
 }
 for(i=0;i<3;i++) if(*(void **)((char *)p+i*4+0x10)) func_021FC830(*(void **)((char *)p+i*4+0x10));
 for(i=0;i<18;i++) if(*(void **)((char *)p+i*4+0x1c)) func_021FC830(*(void **)((char *)p+i*4+0x1c));
 PRINTSYS_QUE_Main(p->f4);
 func_021FD854(p->f64);
 if(p->f8)func_021FD1BC(p->f8);
 return 0;
}









void func_021DE3E4(char *p, char *q)
{
    ((struct CodeinWorkA *)p)->f8 = func_021FD12C(((struct CodeinArgA *)q)->f8, (void *)(*(int *)&((struct CodeinWorkA *)p)->f4), ((struct CodeinWorkA *)p)->f6C);
    func_021FD170(((struct CodeinWorkA *)p)->f8, (char *)(((struct CodeinArgA *)q)->f8), (void *)0x86);
}









/*
 * lever: declaring text before i/flag restores the original stack slots.
 */
void func_021DE404(struct CodeinWorkA *p,char *q)
{
    int font, bank, words;
    struct U16Vec *text;
    int i, flag;
    const Record *rec;
    char *slot;
    void *base;
    font=func_021FC20C(*(char * *)&((struct CodeinArgA *)q)->f8);
    bank=func_021FC214(*(char * *)&((struct CodeinArgA *)q)->f8);
    words=func_021FC21C(*(char * *)&((struct CodeinArgA *)q)->f8);
    func_021FB964((void *)(((struct CodeinArgA *)q)->f8),16,p->f6C);
    for(i=0;i<12;i++) {
        flag=1;
        rec=&d_021E3574[i];
        slot=(char *)p+i*4;
        ((struct CodeinSlotA *)slot)->f1C=func_021FC6A4(1,rec->a,rec->b,rec->c,rec->d,14,p->f4,p->f6C);
        func_021FC868(((struct CodeinSlotA *)slot)->f1C,0,1,0);
        switch(i) {
        case 0: func_0201F02C((struct WordSet *)words,0,func_02012944((*(void * *)&((struct CodeinArgA *)q)->f10))); break;
        case 7: func_0201EFA4((struct WordSet *)words,0,BSUBWAY_SAVEDATA_GetStat(*(Row * *)&((struct CodeinArgA *)q)->f14,5,0),4,1,1); break;
        case 8: func_0201EFA4((struct WordSet *)words,0,BSUBWAY_SAVEDATA_GetStat(*(Row * *)&((struct CodeinArgA *)q)->f14,6,0),4,1,1); break;
        case 9: func_0201EFA4((struct WordSet *)words,0,BSUBWAY_SAVEDATA_GetStat(*(Row * *)&((struct CodeinArgA *)q)->f14,7,0),4,1,1); break;
        case 10: func_0201EFA4((struct WordSet *)words,0,BSUBWAY_SAVEDATA_GetStat(*(Row * *)&((struct CodeinArgA *)q)->f14,8,0),4,1,1); break;
        case 11: func_0201EFA4((struct WordSet *)words,0,BSUBWAY_SAVEDATA_GetStat(*(Row * *)&((struct CodeinArgA *)q)->f14,9,0),4,1,1); break;
        default: text=func_02045EC0((struct MsgBank *)bank,rec->value); flag=0; break;
        }
        if(flag) {
            base=func_02045EC0((struct MsgBank *)bank,rec->value);
            text=STRBUF_Create(128,p->f6C);
            func_0201F250((struct WordSet *)words,text,base);
            STRBUF_Delete(base);
        }
        func_021FC7C4(*(char * *)&((struct CodeinSlotA *)slot)->f1C,text,(void *)font,0x3da0);
        STRBUF_Delete(text);
    }
}









void func_021DE55C(struct CodeinWorkA *p,char *q)
{
    int font, bank, words, i, flag, value;
    const Record *rec;
    char *slot;
    struct U16Vec *text;
    void *base;
    font=func_021FC20C(*(char * *)&((struct CodeinArgA *)q)->f8);
    bank=func_021FC214(*(char * *)&((struct CodeinArgA *)q)->f8);
    words=func_021FC21C(*(char * *)&((struct CodeinArgA *)q)->f8);
    func_021FB964((void *)(((struct CodeinArgA *)q)->f8),17,p->f6C);
    for(i=0;i<18;i++) {
        rec=&d_021E3664[i];
        slot=(char *)p+i*4;
        ((struct CodeinSlotA *)slot)->f1C=func_021FC6A4(1,rec->a,rec->b,rec->c,rec->d,14,p->f4,p->f6C);
        func_021FC868(((struct CodeinSlotA *)slot)->f1C,0,1,0);
        if(i>=8 && i<=12) {value=BSUBWAY_SAVEDATA_GetStat(*(Row * *)&((struct CodeinArgA *)q)->f14,i-3,1);flag=1;}
        else if(i>=13 && i<=17) {value=BSUBWAY_SAVEDATA_GetStat(*(Row * *)&((struct CodeinArgA *)q)->f14,i-8,2);flag=1;}
        else {text=func_02045EC0((struct MsgBank *)bank,rec->value);flag=0;}
        if(flag) {
            base=func_02045EC0((struct MsgBank *)bank,rec->value);
            text=STRBUF_Create(128,p->f6C);
            func_0201EFA4((struct WordSet *)words,0,value,5,1,1);
            func_0201F250((struct WordSet *)words,text,base);
            STRBUF_Delete(base);
        }
        func_021FC7C4(*(char * *)&((struct CodeinSlotA *)slot)->f1C,text,(void *)font,0x3da0);
        STRBUF_Delete(text);
    }
}









void func_021DE66C(struct CodeinWorkA *p,char *q)
{
    int font, bank, words, i, flag, value;
    const Record *rec;
    char *slot;
    struct U16Vec *text;
    void *base;
    font=func_021FC20C(*(char * *)&((struct CodeinArgA *)q)->f8);
    bank=func_021FC214(*(char * *)&((struct CodeinArgA *)q)->f8);
    words=func_021FC21C(*(char * *)&((struct CodeinArgA *)q)->f8);
    func_021FB964((void *)(((struct CodeinArgA *)q)->f8),17,p->f6C);
    for(i=0;i<18;i++) {
        rec=&d_021E35D4[i];
        slot=(char *)p+i*4;
        ((struct CodeinSlotA *)slot)->f1C=func_021FC6A4(1,rec->a,rec->b,rec->c,rec->d,14,p->f4,p->f6C);
        func_021FC868(((struct CodeinSlotA *)slot)->f1C,0,1,0);
        if(i>=8 && i<=12) {value=BSUBWAY_SAVEDATA_GetStat(*(Row * *)&((struct CodeinArgA *)q)->f14,i-8,1);flag=1;}
        else if(i>=13 && i<=17) {value=BSUBWAY_SAVEDATA_GetStat(*(Row * *)&((struct CodeinArgA *)q)->f14,i-13,2);flag=1;}
        else {text=func_02045EC0((struct MsgBank *)bank,rec->value);flag=0;}
        if(flag) {
            base=func_02045EC0((struct MsgBank *)bank,rec->value);
            text=STRBUF_Create(128,p->f6C);
            func_0201EFA4((struct WordSet *)words,0,value,5,1,1);
            func_0201F250((struct WordSet *)words,text,base);
            STRBUF_Delete(base);
        }
        func_021FC7C4(*(char * *)&((struct CodeinSlotA *)slot)->f1C,text,(void *)font,0x3da0);
        STRBUF_Delete(text);
    }
}









/*
 * extent: two trailing zero bytes are alignment padding before the next labelled function.
 */
void func_021DE780(struct CodeinWorkA *p, char *q)
{
    int i;
    for (i = 0; i < 18; i++) {
        char *slot = (char *)p + i * 4;
        if (((struct CodeinSlotA *)slot)->f1C != 0) {
            func_021FC734(((struct CodeinSlotA *)slot)->f1C);
            ((struct CodeinSlotA *)slot)->f1C = 0;
        }
    }
    func_021FBDA4(((struct CodeinArgA *)q)->f8, 17);
    if (p->f8 != 0) {
        func_021FD15C(p->f8, ((struct CodeinArgA *)q)->f8);
        p->f8 = 0;
    }
}









/*
 * lever: bank/words declaration order selects their original stack slots.
 * omits func_02045CAC from its function header. Existing C verified EXACT
 * (344 bytes, 12/12 relocations; ARM9-45CAC-one.log, terminal exit 0).
 * typedef unsigned char  u8;
 * typedef unsigned short u16;
 * typedef unsigned int   u32;
 *
 * struct MsgEntry {
 *     u32 off;
 *     u16 len;
 *     u16 pad_06;
 * };
 *
 * struct MsgFile {
 *     u16 langCount;
 *     u16 count;
 *     u32 unk_04;
 *     u32 unk_08;
 *     u32 langOff[1];
 * };
 *
 * struct MsgBank {
 *     const struct MsgFile *file;
 *     void                 *base;
 *     struct MsgEntry       cache;
 *     u32                   origin;
 *     void                 *stream;
 *     u16                   heapId;
 *     u8                    langIndex;
 *     u8                    resident;
 * };
 *
 * extern char MSGDATA_AllocSite[];
 * extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site,
 *                           u16 tag);
 * extern void func_020307B0(void *p);
 * extern void ARC_TOOL_ReadHandle(void *stream, u32 size, void *dest);
 * extern void func_0204960C(void *stream, u32 pos);
 * extern void STRBUF_Clear(void *dest);
 * extern void STRBUF_SetChars(void *dest, const void *src, u16 len);
 * extern void func_02045E04(void *dest, u32 index);
 * extern u8 func_020461B8(const void *file);
 * extern void MSGDATA_LoadBank(struct MsgBank *bank);
 * extern void func_02046180(struct MsgBank *bank);
 *
 * void func_02045CAC(struct MsgBank *bank, u32 index, void *dest)
 * {
 *     u32 size;
 *     struct MsgEntry *e;
 *
 *     if (index >= bank->file->count) {
 *         STRBUF_Clear(dest);
 *         return;
 *     }
 *
 *     func_02046180(bank);
 *
 *     if (bank->resident == 0) {
 *         u32 pos = bank->origin + bank->file->langOff[bank->langIndex];
 *
 *         func_0204960C(bank->stream, pos + (index * 8 + 4));
 *         ARC_TOOL_ReadHandle(bank->stream, 8, &bank->cache);
 *         e = &bank->cache;
 *     } else {
 *         e = (struct MsgEntry *)((u8 *)bank->base + 4) + index;
 *     }
 *
 *     if (bank->resident == 0) {
 *         void *buf;
 *
 *         size = e->len * 2;
 *         buf = sub_02030734((u16)((bank->heapId & 0x7fff) | 0x8000), size,
 *                            0, MSGDATA_AllocSite, 0xd6);
 *         if (buf != 0) {
 *             func_0204960C(bank->stream,
 *                           e->off + (bank->origin
 *                               + bank->file->langOff[bank->langIndex]));
 *             ARC_TOOL_ReadHandle(bank->stream, size, buf);
 *             STRBUF_SetChars(dest, buf, e->len);
 *             func_020307B0(buf);
 *         }
 *     } else {
 *         STRBUF_SetChars(dest, (u8 *)bank->base + e->off, e->len);
 *     }
 *
 *     func_02045E04(dest, index);
 * }
 */
void func_021DE7C0(char *p,char *q)
{
    int font,words,bank,i;
    Params config;
    Triple triple;
    struct U16Vec *base,*text;
    void *value;
    const Record *rec;
    char *slot;
    func_021FBE54(*(char **)(q+8),6,*(u16 *)(p+0x6c));
    func_021FB964((void *)(*(int *)(q+8)),15,*(u16 *)(p+0x6c));
    font=func_021FC20C(*(char **)(q+8));
    bank=func_021FC214(*(char **)(q+8));
    words=func_021FC21C(*(char **)(q+8));
    func_02082BCC(&config,0,8);
    config.a=80; config.b=168; config.c=0; config.flag=1;
    func_021FC124((void *)(*(void **)(q+8)), 6, (Triple *)&triple);
    *(void **)(p+0xc)=func_021FB378(&config,4,96,1,*(int *)q,*(int *)p,font,bank,&triple,*(u16 *)(p+0x6c));
    base=STRBUF_Create(128,*(u16 *)(p+0x6c));
    text=STRBUF_Create(128,*(u16 *)(p+0x6c));
    value=func_02012944(*(void **)(q+0x10));
    for(i=0;i<3;i++) {
        rec=&d_021E351C[i];
        slot=p+i*4;
        *(void **)(slot+0x10)=func_021FC6A4(4,rec->a,rec->b,rec->c,rec->d,14,*(void **)(p+4),*(u16 *)(p+0x6c));
        if(i==0) {
            func_02045CAC((struct MsgBank *)bank,rec->value,base);
            func_0201F02C((struct WordSet *)words,0,value);
            func_0201F250((struct WordSet *)words,text,base);
        } else func_02045CAC((struct MsgBank *)bank,rec->value,text);
        func_021FC7C4(*(char **)(slot+0x10),text,(void *)font,0x3da0);
    }
    STRBUF_Delete(base);
    STRBUF_Delete(text);
}









void func_021DE8FC(struct CodeinWorkA *p, char *q)
{
    int i;
    for (i = 0; i < 3; i++) {
        char *slot = (char *)p + i * 4;
        if (((struct CodeinWorkC *)slot)->f10) {
            func_021FC734(((struct CodeinWorkC *)slot)->f10);
            ((struct CodeinWorkC *)slot)->f10 = 0;
        }
    }
    if (p->fC) {
        func_021FB494(p->fC);
        p->fC = 0;
    }
    func_021FC0C8((char *)(((struct CodeinArgA *)q)->f8), 6);
    func_021FBDA4(((struct CodeinArgA *)q)->f8, 15);
}









int func_021DE940(struct CodeinWorkA *p, int x, int y)
{
    int skip = p->f68;
    int i;
    for (i = 0; i < 4; i++) {
        if (i != skip && (u32)(x - d_021E3534[i].x0) <= d_021E3534[i].x1 - d_021E3534[i].x0 &&
            (u32)(y - d_021E3534[i].y0) <= d_021E3534[i].y1 - d_021E3534[i].y0) {
            Point args;
            args.x = x;
            args.y = y;
            func_021FD860((void *)(*(int *)&p->f64), 1, &args);
            func_020061E4(0x703);
            return i;
        }
    }
    return 0;
}









int func_021DE9A0(void *a, int b, char *q)
{
    struct CodeinWorkD *p = PROCSYS_AllocProcWork(a, 0x10C, func_021F9B9C((*(void * *)&((struct CodeinArgA *)q)->f14)));
    int i;
    func_02082BCC(p, 0, 0x10C);
    p->f108 = q;
    p->f18 = func_021F9B9C((*(void * *)&((struct CodeinArgA *)q)->f14));
    p->f0 = BMP_OAM_CreateSys(p->f18, ((struct CodeinArgA *)q)->fC);
    p->f14 = (void *)func_0201C440((void *)(p->f18));
    for (i = 0; i < 2; i++)
        *(void **)((char *)p + i * 4 + 0x1C) = func_021FD760((unsigned int)(((struct CodeinArgA *)q)->fC), (char *)(((struct CodeinArgA *)q)->f10), i, p->f18);
    p->f10 = func_021FD6D8((int)p, (int)func_021DF0DC, p->f18);
    if (((struct CodeinSubA *)(p->f108))->f4 != 0)
        func_021FD73C(p->f10, (int)func_021DEB4C);
    else
        func_021FD73C(p->f10, (int)func_021DF0DC);
    return 1;
}









int func_021DEA30(void *a, int b, struct CodeinArgA *q, struct CodeinWorkA *p)
{
    int i;
    if (p->f100 != 0) {
        func_021DF388((char *)p + 0x28);
        p->f100 = 0;
    }
    if (p->fC != 0) {
        func_021FC734(p->fC);
        p->fC = 0;
    }
    if (p->f8 != 0) {
        func_021FC734(p->f8);
        p->f8 = 0;
    }
    if (p->f4 != 0) {
        func_021FB494(p->f4);
        p->f4 = 0;
    }
    if (p->f104 != 0) {
        func_021FC0C8((*(void * *)&((struct CodeinSubA *)(p->f108))->f10), 6);
        func_021FBDA4((int)((*(void * *)&((struct CodeinSubA *)(p->f108))->f10)), 24);
        p->f104 = 0;
    }
    func_021FD714(p->f10);
    if (p->f24 != 0) {
        func_021FD15C(p->f24, q->f10);
        p->f24 = 0;
    }
    for (i = 0; i < 2; i++) func_021FD820(*(void **)((char *)p + 0x1C + i * 4));
    BMP_OAM_DeleteSys(p->f0);
    func_0201C4C0(p->f14);
    func_020315D4(a);
    return 1;
}









int func_021DEADC(int a, int b, int c, struct CodeinWorkA *p)
{
    int i;
    if (func_021FF88C(((struct CodeinSubA *)(p->f108))->f18) == 2) {
        func_021F9C6C((*(void * *)&((struct CodeinSubA *)(p->f108))->f14));
        return 1;
    }
    func_021FD71C(p->f10);
    if (func_021FD72C(p->f10) != 0) return 1;
    for (i = 0; i < 2; i++) func_021FD854(*(void **)((char *)p + 0x1C + i * 4));
    PRINTSYS_QUE_Main(p->f14);
    if (p->f8 != 0) func_021FC830(p->f8);
    if (p->fC != 0) func_021FC830(p->fC);
    if (p->f24 != 0) func_021FD1BC(p->f24);
    return 0;
}









void func_021DEB4C(int *task,int *state,struct CodeinWorkD *p)
{
    int font,bank;
    Params config;
    Triple triple;
    font=func_021FC20C(*(char * *)&((struct CodeinSubA *)(p->f108))->f10);
    bank=func_021FC214(*(char * *)&((struct CodeinSubA *)(p->f108))->f10);
    if(p->f24) {
        func_021FD15C(p->f24,((struct CodeinSubA *)(p->f108))->f10);
        p->f24=0;
    }
    func_021FB964((void *)(((struct CodeinSubA *)(p->f108))->f10),24,p->f18);
    func_021FBE54(*(char * *)&((struct CodeinSubA *)(p->f108))->f10,6,p->f18);
    p->f104=1;
    func_02082BCC(&config,0,8);
    config.a=80;config.b=168;config.c=0;config.flag=1;
    if(!func_021FC124((void *)((*(void * *)&((struct CodeinSubA *)(p->f108))->f10)), 6, (Triple *)&triple))
        func_02034714(d_021E3964,0,d_021E3964);
    p->f4=func_021FB378(&config,4,96,1,(*(int *)&((struct CodeinSubA *)(p->f108))->fC),(*(int *)&p->f0),font,bank,&triple,p->f18);
    p->f8=func_021FC6A4(4,11,6,10,4,14,p->f14,p->f18);
    func_021FC754(*(char * *)&p->f8,(void *)bank,(void *)0x55,(void *)font,0x3da0);
    p->fC=func_021FC6A4(1,3,3,26,4,14,p->f14,p->f18);
    func_021FC868(p->fC,0,1,0);
    func_021FC754(*(char * *)&p->fC,(void *)bank,(void *)(**(int * *)&p->f108+0x57),(void *)font,0x3da0);
    func_021DF1DC((Menu *)((char *)p+0x28), ((struct CodeinSubA *)(p->f108))->f1C, *(char * *)&((struct CodeinSubA *)(p->f108))->f10, (*(int *)&((struct CodeinSubA *)(p->f108))->fC), (u32)(p->f1C), (u32)((*(void * *)&p->f20)), *(u16 * *)&((struct CodeinSubA *)(p->f108))->f28, p->f18);
    p->f100=1;
    func_021FD73C(task,(int)func_021DED14);
}









void func_021DECB0(void *a, int b, struct CodeinWorkA *p)
{
    func_021DF388((char *)p + 0x28);
    p->f100 = 0;
    func_021FC734(p->fC);
    p->fC = 0;
    func_021FC734(p->f8);
    p->f8 = 0;
    func_020409B4(4);
    func_020409B4(1);
    func_021FB494(p->f4);
    p->f4 = 0;
    func_021FC0C8((*(void * *)&((struct CodeinSubA *)(p->f108))->f10), 6);
    func_021FBDA4((int)((*(void * *)&((struct CodeinSubA *)(p->f108))->f10)), 24);
    p->f104 = 0;
    func_021FD744((int *)a);
}









void func_021DED14(int *a, int *state, struct CodeinWorkA *p)
{
    switch (*state) {
    case 0:
        func_021FE784((int)((*(void * *)&((struct CodeinSubA *)(p->f108))->f8)), 2, 3, 0);
        *state = 1;
        break;
    case 1:
        if (func_021FE7B0(((struct CodeinSubA *)(p->f108))->f8) != 0) *state = 2;
        break;
    case 2:
        func_021FD73C(a, (int)func_021DEDB4);
        break;
    }
}









void func_021DED64(int *p, int *state, struct CodeinArgA *q)
{
    switch (*state) {
    case 0:
        func_021FE784((int)(((struct CodeinSubA *)(q->f108))->f8), 2, 3, 1);
        *state = 1;
        break;
    case 1:
        if (func_021FE7B0(((struct CodeinSubA *)(q->f108))->f8) != 0) *state = 2;
        break;
    case 2:
        func_021FD73C(p, (int)func_021DECB0);
        break;
    }
}









void func_021DEDB4(int *task, int *state, char *p)
{
    u32 x,y;
    func_021DF3DC(p+0x28,((struct CodeinWorkD *)p)->f18);
    if (func_02035D20(&x,&y)) {
        if (func_021FB4B4((unsigned int *)((*(int *)&((struct CodeinWorkD *)p)->f4)),x,y)) {
            Point args;
            args.x=x; args.y=y;
            func_021FD860((void *)(((struct CodeinWorkD *)p)->f20), 1, &args);
            func_021F9BA0((*(void * *)&((struct CodeinSubA *)(((struct CodeinWorkD *)p)->f108))->f14));
            func_021FD73C(task,(int)func_021DED64);
        }
        if (func_021DF8F0(x,y)) {
            u32 selection;
            Point args;
            selection=func_021DF41C(p+0x28);
            if (selection>=((struct CodeinSubA *)(((struct CodeinSubA *)(((struct CodeinWorkD *)p)->f108))->f1C))->f1718)
                func_02034714(d_021E3964,0,d_021E3964);
            ((struct CodeinSubA *)(((struct CodeinSubA *)(((struct CodeinWorkD *)p)->f108))->f1C))->f171C=selection;
            func_021F9BF4(*(unsigned * *)&((struct CodeinSubA *)(((struct CodeinWorkD *)p)->f108))->f14,2);
            func_021FD73C(task,(int)func_021DED64);
            args.x=x; args.y=y;
            func_021FD860((void *)(((struct CodeinWorkD *)p)->f20), 1, &args);
        }
    }
}







void func_021DEE7C(int *task,u32 *state,char *p)
{
    switch(*state) {
    case 0: {
        Point initial;
        int mode;
        func_02082BCC(&initial,0,8);
        switch(**(u32 **)(p+0x108)) {
        case 0: mode=5; break;
        case 1: mode=6; break;
        case 2: mode=7; break;
        case 3: initial=*(Point *)(*(char **)(p+0x108)+0x20); mode=4; break;
        default: func_02034714(d_021E3964,0,d_021E3964); break;
        }
        func_02082BCC(*(void **)(*(char **)(p+0x108)+0x1c),0,0x1720);
        *(u32 *)(p+0xfc)=0;
        func_021FF54C(*(void **)(*(char **)(p+0x108)+0x18),mode,(const int *)(&initial));
        *state=1; break;
    }
    case 1:
        ++*(u32 *)(p+0xfc);
        if(func_021FF648(*(char **)(*(char **)(p+0x108)+0x18)) && *(u32 *)(p+0xfc)>96) {
            func_021FD860((void *)(*(int *)(p+0x1c)), 0, 0); *state=2;
        } break;
    case 2: {
        int message,success,i;
        struct Data_021DB2E0 *data;
        enum { COUNT_OFFSET=0x1718 } offset;
        data=*(struct Data_021DB2E0 **)(*(char **)(p+0x108)+0x1c);
        offset=COUNT_OFFSET;
        if(!func_021FF72C(*(void **)(*(char **)(p+0x108)+0x18),&message)) {
            switch(**(u32 **)(p+0x108)) {
            case 0: success=func_021FF6DC(*(void **)(*(char **)(p+0x108)+0x18),data,30,(void *)((u32)data+offset)); break;
            case 1: success=func_021FF6DC(*(void **)(*(char **)(p+0x108)+0x18),data,30,(void *)((u32)data+offset)); break;
            case 2: success=func_021FF704(*(void **)(*(char **)(p+0x108)+0x18),data,30,(void *)((u32)data+offset)); break;
            case 3: success=func_021FF6B4(*(void **)(*(char **)(p+0x108)+0x18),data,30,(void *)((u32)data+offset)); break;
            default: func_02034714(d_021E3964,0,d_021E3964); break;
            }
            if(success) {
                for(i=0;i<(*(struct Data_021DB2E0 **)(*(char **)(p+0x108)+0x1c))->count;i++) {
                    *(u8 *)(*(char **)(*(char **)(p+0x108)+0x1c)+i+0x16f8)=(u8)BATTLE_REC_GetHeaderParam((u8 *)(*(char **)(*(char **)(p+0x108)+0x1c)+i*0xc4+0x80),5,0);
                }
                func_021FD73C(task,(int)func_021DF18C);
            } else {
                if(**(u32 **)(p+0x108)==3) func_021FD170(*(void **)(p+0x24),(char *)(*(int *)(*(char **)(p+0x108)+0x10)),(void *)276);
                else func_021FD170(*(void **)(p+0x24),(char *)(*(int *)(*(char **)(p+0x108)+0x10)),(void *)339);
                *state=3;
            }
        } else {
            func_021FD170(*(void **)(p+0x24),(char *)(*(int *)(*(char **)(p+0x108)+0x10)),(void *)message);
            *state=3;
        } break;
    }
    case 3: {
        u32 x,y;
        Point clicked;
        if(TOUCHPANEL_GetTrg()) {
            func_02035D20(&x,&y);
            clicked.x=x; clicked.y=y;
            func_021FD860((void *)(*(int *)(p+0x20)), 1, &clicked);
            func_020061E4(0x703);
            func_021FE784(*(int *)(*(char **)(p+0x108)+8),2,3,1);
            *state=4;
        } break;
    }
    case 4:
        if(func_021FE7B0(*(int **)(*(char **)(p+0x108)+8))) *state=5;
        break;
    case 5:
        func_021F9BA0(*(void **)(*(char **)(p+0x108)+0x14)); func_021FD744((int *)task); break;
    }
}







void func_021DF0DC(int *p, int *state, struct CodeinArgA *q)
{
    Point args;
    switch (*state) {
    case 0:
        if (q->f24 == 0) {
            q->f24 = (int)func_021FD12C(((struct CodeinSubA *)(q->f108))->f10, (void *)(q->f14), q->f18);
        }
        if (**(int * *)&q->f108 == 3) {
            func_021FD170((char *)(q->f24), (char *)(((struct CodeinSubA *)(q->f108))->f10), (void *)0x14B);
        } else {
            func_021FD170((char *)(q->f24), (char *)(((struct CodeinSubA *)(q->f108))->f10), (void *)0x13E);
        }
        args.x = 0x80;
        args.y = 0x60;
        func_021FD860((void *)(q->f1C), 4, &args);
        *state = 1;
        break;
    case 1:
        func_021FE784((int)(((struct CodeinSubA *)(q->f108))->f8), 2, 3, 0);
        *state = 2;
        break;
    case 2:
        if (func_021FE7B0(((struct CodeinSubA *)(q->f108))->f8) != 0) *state = 3;
        break;
    case 3:
        func_021FD73C(p, (int)func_021DEE7C);
        break;
    }
}







void func_021DF18C(int *p, int *state, struct CodeinArgA *q)
{
    switch (*state) {
    case 0:
        func_021FE784((int)(((struct CodeinSubA *)(q->f108))->f8), 2, 3, 1);
        *state = 1;
        break;
    case 1:
        if (func_021FE7B0(((struct CodeinSubA *)(q->f108))->f8) != 0) *state = 2;
        break;
    case 2:
        func_021FD73C(p, (int)func_021DEB4C);
        break;
    }
}





void func_021DF1DC(Menu *p,char *base,char *res,u32 mgr,u32 a5,u32 a6,u16 *sel,u16 heap)
{
    unsigned first,second;
    int i;
    void *bmp;
    void *buf1,*msg,*buf2;
    Config_021DF1DC cfg;
    first=func_021FC20C(res);
    second=func_021FC214(res);
    func_02082BCC(p,0,0xd4);
    p->base=base;
    p->words=func_0201EC64(heap);
    p->c=a5;
    p->d=a6;
    p->list=BMP_MENUWORK_Create(*(u32 *)(base+0x1718),heap);
    for(i=0;i<*(int *)(base+0x1718);i++)p->list[i].b=i;
    *(CfgTpl *)&cfg=d_021E3700;
    cfg.list=(Item *)p->list;
    cfg.count=*(u32 *)(base+0x1718);
    cfg.resources=res;
    cfg.manager=mgr;
    cfg.cursor=p->c;
    cfg.other=p->d;
    cfg.selection=sel;
    p->view=func_021FC8C8((const Config_021DF1DC *)&cfg, heap);
    buf1=STRBUF_Create(0xff,heap);
    msg=func_02045EC0((struct MsgBank *)second,0x7a);
    buf2=STRBUF_Create(0xff,heap);
    for(i=0;i<*(int *)(base+0x1718);i++){
        bmp=BMP_Create(cfg.width,cfg.spacing,0x20,heap);
        BMP_Clear(bmp,0);
        func_0201EFA4(p->words,0,i+1,2,0,1);
        func_0201F250(p->words,buf1,msg);
        STRBUF_SetString(buf2,(const u16 *)(base+i*0xc4));
        PRINTSYS_PrintColor(bmp,(short)(16-func_0201D304(buf1,first,0)),4,buf1,(void *)first,0x3DA0);
        PRINTSYS_PrintColor(bmp,0x14,4,buf2,(void *)first,0x3DA0);
        func_021FCDAC(p->view,(u16)i,(u32)bmp);
    }
    STRBUF_Delete(buf2);
    STRBUF_Delete(buf1);
    STRBUF_Delete(msg);
    func_021FCE50(p->view);
    func_021DF428((struct State_021DF428 *)p,mgr,heap);
    for(i=0;i<*sel;i++)func_021DF620((struct State_021DF428 *)p,i+1,1,heap);
}





/*
 * trailing: two zero alignment bytes at 0x021DF3DA
 */
void func_021DF388(char *p)
{
    unsigned int i;
    func_021DF5B8(p);
    for (i = 0; i < func_021FCE0C(((struct CodeinWorkG *)p)->f4, 3); i++) {
        BMP_Delete((struct Obj020437AC *)func_021FCDE8(((struct CodeinWorkG *)p)->f4, i));
    }
    func_0201ED04(((struct CodeinWorkG *)p)->f8);
    func_021FCC80(((struct CodeinWorkG *)p)->f4);
    BMP_MENUWORK_Delete(((struct CodeinWorkG *)p)->f0);
    func_02082BCC(p, 0, 0xD4);
}





/*
 * trailing: two zero alignment bytes at 0x021DF41A
 */
void func_021DF3DC(char *p, u16 a)
{
    unsigned int old, current;
    s8 direction;
    old = func_021FCE0C(((struct CodeinWorkD *)p)->f4, 1);
    func_021FCD0C(((struct CodeinWorkD *)p)->f4);
    current = func_021FCE0C(((struct CodeinWorkD *)p)->f4, 1);
    direction = func_021FCE0C(((struct CodeinWorkD *)p)->f4, 2);
    if (direction != 0 && old != current) func_021DF620((struct State_021DF428 *)p, current, direction, a);
}








int func_021DF41C(char *p)
{
    return func_021FCDA8(*(char * *)&((struct CodeinWorkA *)p)->f4);
}








/*
 * 2026-10-05 (wave P6 lane U1b): EXACT. Types from matched ov183 021DF1DC (Menu: base
 * at +0xD0) and 021DF620 (State layout). Two fixes closed the earlier 24 B residue:
 * heap is a u16 parameter (it is only masked and passed to u16-style callees; the
 * narrow type moves its home store before mgr's), and the clamp is a ternary
 * `n = (n >= 5) ? 5 : n;` which gives n the lowest spill slot, under the loop temps.
 * Final call is an if/else with a call in each arm.
 */
void func_021DF428(struct State_021DF428 *p,u32 mgr,u16 heap)
{
    int i,j;
    void *archive;
    u32 mode,species;
    int n;
    struct Entries e;
    struct Pos pos;
    n=*(int *)(p->source+0x1718);
    n=(n>=5)?5:n;
    mode=(heap&0x7fff)|0x8000;
    archive=func_020490F4(7,(u16)mode);
    i=0;
    p->shared0=CLACT_RegisterPaletteCompressed(archive,func_0201BC3C(),0,0x80,heap);
    p->shared1=CLACT_RegisterCellAnim(archive,func_0201BC40(),func_0201BCB4(),heap);
    func_02082BCC(&pos,0,8);
    pos.z=1;
    pos.a=i;
    pos.b=i;
    for(i=0;i<n;i++) {
        func_021DF838((int)(p->source+i*0xc4),(char *)(&e));
        for(j=0;j<6;j++) {
            species=e.species[j];
            if(species==0) species=1;
            p->indices[i][j]=CLACT_RegisterCharacter(archive,POKE_TOOL_CalcGraphicIndex(species,e.form[j],e.gender[j],0),0,0,heap);
            pos.x=j*0x18+0x6e;
            pos.y=i*0x18+0x48;
            pos.a=6-j;
            p->sprites[i][j]=CLACT_CreateActor((void *)mgr,p->indices[i][j],p->shared0,p->shared1,&pos,0,heap);
            func_0204B6F4(p->sprites[i][j],func_0201BB5C(species,e.form[j],e.gender[j],0),0);
            func_0204B688(p->sprites[i][j],1);
            if(e.species[j]==0) func_0204B3DC(p->sprites[i][j],0);
            else func_0204B3DC(p->sprites[i][j],1);
        }
    }
    ARC_TOOL_DeleteHandle(archive);
}








/*
 * trailing: two zero alignment bytes at 0x021DF61E
 * lever: padded struct array members prevent caching the element cursor across calls.
 */
void func_021DF5B8(char *p)
{
    int i, j;
    CLACT_ReleaseCellAnim(((struct CodeinWorkG *)p)->f16);
    CLACT_ReleasePalette(((struct CodeinWorkG *)p)->f14);
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 6; j++) {
            if (((struct W *)p)->objects[i][j] != 0) {
                CLACT_ReleaseCharacter(((struct W *)p)->handles[i][j]);
                CLACT_DeleteActor(((struct W *)p)->objects[i][j]);
                ((struct W *)p)->objects[i][j] = 0;
            }
        }
    }
}








/*
 * Lever: short step spills first; i remains live after the first loop and
 * supplies the second loop's row; forward/back/loaded declaration order
 * gives the three 36-byte buffers at sp+7c, sp+58, sp+34.
 */
void func_021DF620(struct State_021DF428 *p,int first,short step,u16 heap)
{
    int i,j;
    char *src,*dst;
    u32 value;
    void *archive,*handle;
    struct Sub *data;
    struct Rec forward,back,loaded;
    struct Entries entries;
    u32 mode;
    for(i=0;i<5;i++) {
        for(j=0;j<6;j++) {
            if(step==1 && i!=4) {
                src=p->sprites[i+1][j]; dst=p->sprites[i][j];
                if(func_0204B3F4((struct Obj *)src)) {
                    CLACT_GetActorImageProxy(src,(struct Struct36 *)(&forward));
                    value=func_0204B714((struct Obj *)src);
                    CLACT_SetActorImageProxy(dst,(const struct Struct36 *)(&forward));
                    func_0204B6F4((struct Obj *)dst,value,0);
                    func_0204B3DC((struct Obj *)dst,1);
                } else func_0204B3DC((struct Obj *)dst,0);
            } else if(step==-1 && i!=4) {
                src=p->sprites[3-i][j]; dst=p->sprites[4-i][j];
                if(func_0204B3F4((struct Obj *)src)) {
                    CLACT_GetActorImageProxy(src,(struct Struct36 *)(&back));
                    value=func_0204B714((struct Obj *)src);
                    CLACT_SetActorImageProxy(dst,(const struct Struct36 *)(&back));
                    func_0204B6F4((struct Obj *)dst,value,0);
                    func_0204B3DC((struct Obj *)dst,1);
                } else func_0204B3DC((struct Obj *)dst,0);
            }
        }
    }
    mode=(heap&0x7fff)|0x8000;
    archive=func_020490F4(7,(u16)mode);
    if(step==-1) { --p->cursor; if(p->cursor<0) p->cursor=4; }
    for(j=0;j<6;j++) {
        if(step==1) i=4; else if(step==-1) i=0;
        func_021DF838((int)((u32)p->source+(i+first)*0xc4),(char *)&entries);
        if(entries.species[j]) {
            handle=func_02049E74(archive,POKE_TOOL_CalcGraphicIndex(entries.species[j],entries.form[j],entries.gender[j],0),0,(u32)&data,mode);
            CLACT_TransferCharacter(p->indices[p->cursor][j],(struct Sub0204A9D0 *)data);
            CLACT_GetCharacterProxy(p->indices[p->cursor][j],&loaded);
            CLACT_SetActorImageProxy(p->sprites[i][j],(const struct Struct36 *)(&loaded));
            func_0204B6F4((struct Obj *)p->sprites[i][j],func_0201BB5C(entries.species[j],entries.form[j],entries.gender[j],0),0);
            func_020307B0(handle);
            func_0204B3DC((struct Obj *)p->sprites[i][j],1);
        } else func_0204B3DC((struct Obj *)p->sprites[i][j],0);
    }
    if(step==1) { ++p->cursor; if(p->cursor>4) p->cursor=0; }
    ARC_TOOL_DeleteHandle(archive);
}








/*
 * 2026-10-05 (D8 lane19): re-verified, status unchanged; sole blocker is arm9 callee 0x0200B98C (no witness outside the caller). Needs a label seed. Source is byte-correct; no C change possible.
 * blocker-symbols: BattleRecModeTable 0x0209DDCC data a4
 * + *   typedef unsigned char u8;
 *   typedef unsigned short u16;
 *   typedef unsigned long long u64;
 *   extern const u16 BattleRecModeTable[];
 *   u64 BATTLE_REC_GetHeaderParam(char *p, int selector, int index)
 *   {
 *       int i;
 *       u16 v;
 *       switch (selector) {
 *       case 0:
 *           v = ((u16 *)p)[index];
 *           if (v > 0x289) return 0;
 *           return v;
 *       case 1:
 *           return *(u8 *)(p + index + 0x18) & 0x7F;
 *       case 2:
 *           v = *(u16 *)(p + 0x24);
 *           if (v > 0x270F) return 0x270F;
 *           return v;
 *       case 3:
 *           for (i = 0; i < 0x29; i++) {
 *               if (*(u16 *)(p + 0x26) == BattleRecModeTable[i]) return i;
 *           }
 *           return 0;
 *       case 4:
 *           return *(u64 *)(p + 0x38);
 *       case 5:
 *           return *(u8 *)(p + 0x2A);
 *       case 6:
 *           return (*(u8 *)(p + index + 0x18) & 0x80) >> 7;
 *       case 7:
 *           return *(u8 *)(p + 0x2B);
 *       default:
 *           return 0;
 *       }
 *   }
 * checks: 1 full callee reads 3 args, 64-bit return; 2 no filed twin; 3 int base/long index unchanged (2/2); 4 named base and second declaration order close DIFF (2/2); 5 fresh idiom/neighbour reread, no stack-object residue. Both reorder variants consumed.
 */
void func_021DF838(int p, char *out)
{
    long i;
    int a, b, c;
    void *base;
    int special, n = 0;
    unsigned int count;
    func_02082BCC(out, 0, 0x48);
    base = (void *)(p + 0x80);
    switch ((int)BATTLE_REC_GetHeaderParam(base, 3, 0)) {
    case 16: case 17: case 18: case 19: case 22:
        special = 1;
        count = 9;
        break;
    default:
        special = 0;
        count = 6;
        break;
    }
    for (i = 0; i < count; i++) {
        if (special && i >= 3 && i <= 5) continue;
        a = BATTLE_REC_GetHeaderParam(base, 0, i);
        b = BATTLE_REC_GetHeaderParam(base, 1, i);
        c = BATTLE_REC_GetHeaderParam(base, 6, i);
        if (a >= 0x28B) a = 0;
        if (a != 0) {
            *(int *)(out + n * 4) = a;
            *(int *)(out + n * 4 + 0x18) = b;
            *(int *)(out + n * 4 + 0x30) = c;
            n++;
        }
    }
}








int func_021DF8F0(int x, int y)
{
    int ok = ((unsigned)(x - 80) <= 88) & ((unsigned)(y - 32) <= 56);
    if (ok) func_020061E4(0x703);
    return ok;
}








int func_021DF920(void *obj, int unused, struct CodeinArgB *q)
{
    struct CodeinWorkA *p;
    int i;
    p = PROCSYS_AllocProcWork(obj, 0x58, func_021F9B9C((struct Obj24810 *)(q->fC)));
    func_02082BCC(p, 0, 0x58);
    p->f54 = func_021F9B9C((struct Obj24810 *)(q->fC));
    p->f48 = (void *)func_0201C440((void *)(p->f54));
    (*(void * *)&p->f44) = BMP_OAM_CreateSys(p->f54, q->f4);
    (*(int *)&p->f38) = (int)func_021FD12C(q->f8, (void *)(*(int *)&p->f48), p->f54);
    func_021FD170((char *)((*(int *)&p->f38)), (char *)(q->f8), (void *)0x6B);
    for (i = 0; i < 2; i++) {
        *(int *)((char *)p + i * 4 + 0x3C) = (int)func_021FD760(*(int *)&q->f4, (char *)(q->f8), i, p->f54);
    }
    q->f14 = 0xFFFF;
    q->f16 = 0xFF;
    q->f17 = 0xFF;
    q->f18 = 0x13;
    func_021FBE54((char *)(q->f8), 6, p->f54);
    func_021E02F8(p, (int *)q);
    return 1;
}








int func_021DF9C8(void *p, int unused, struct CodeinArgA *q, char *data)
{
    int i;
    func_021E037C(data, q);
    func_021FC0C8((char *)(q->f8), 6);
    for (i = 0; i < 2; i++) func_021FD820(*(char **)(data + i * 4 + 0x3c));
    func_021FD15C(((struct CodeinDataA *)data)->f38, q->f8);
    BMP_OAM_DeleteSys(((struct CodeinDataA *)data)->f44);
    func_0201C4C0(((struct CodeinDataA *)data)->f48);
    func_020315D4(p);
    return 1;
}








int func_021DFA10(void *unused,u32 *state,int *q,char *p)
{
    int i;
    switch(*state) {
    case 0: if(d_021E37A8[*(int *)(p+0x4c)].init(p,q)) ++*state; break;
    case 1: func_021FE784(q[0],2,3,0); ++*state; break;
    case 2: if(func_021FE7B0((int *)q[0])) *state=3; break;
    case 3: if(d_021E37A8[*(int *)(p+0x4c)].update(p,q)) {
        if(((struct CodeinWorkA *)p)->f50==-1) *state=10; else *state=4;
    } break;
    case 4: func_021FE784(q[0],2,2,1); ++*state; break;
    case 5: if(func_021FE7B0((int *)q[0])) ++*state; break;
    case 6: if(d_021E37A8[*(int *)(p+0x4c)].finish(p,q)) {
        ((struct CodeinWorkA *)p)->f4C=((struct CodeinWorkA *)p)->f50; ++*state;
    } break;
    case 7: if(d_021E37A8[*(int *)(p+0x4c)].init(p,q)) ++*state; break;
    case 8: func_021FE784(q[0],2,2,0); ++*state; break;
    case 9: if(func_021FE7B0((int *)q[0])) *state=3; break;
    case 10: func_021FE784(q[0],2,3,1); ++*state; break;
    case 11: if(func_021FE7B0((int *)q[0])) *state=12; break;
    case 12: if(d_021E37A8[*(int *)(p+0x4c)].finish(p,q)) return 1; break;
    }
    for(i=0;i<3;i++) if(*(void **)(p+i*4)) func_021FC830(*(void **)(p+i*4));
    for(i=0;i<6;i++) if(*(void **)(p+0x20+i*4)) func_021FC830(*(void **)(p+0x20+i*4));
    if(((struct CodeinWorkA *)p)->f38) func_021FD1BC(((struct CodeinWorkA *)p)->f38);
    PRINTSYS_QUE_Main(((struct CodeinWorkA *)p)->f48);
    for(i=0;i<2;i++) func_021FD854(*(char **)(p+0x3c+i*4));
    return 0;
}








int func_021DFB90(struct CodeinWorkA *p,struct CodeinArgA *q)
{
    int first,second,i;
    Params req;
    Triple triple;
    const struct Rec6 *r;
    const struct Rec8 *s;
    first=func_021FC20C(*(char * *)&q->f8);
    second=func_021FC214(*(char * *)&q->f8);
    func_021FB964((void *)(q->f8),26,p->f54);
    func_02082BCC(&req,0,8);
    func_021FC124((void *)q->f8,6,&triple);
    for(i=0;i<2;i++) {
        r=&d_021E3734[i];
        req.a=r->x; req.b=r->y; req.c=r->id; req.flag=1;
        *(void **)((char *)p+0xc+i*4)=func_021FB378(&req,r->file,0x60,1,q->f4,p->f44,first,second,&triple,p->f54);
    }
    for(i=0;i<3;i++) {
        s=&d_021E3740[i];
        *(void **)((char *)p+i*4)=func_021FC6A4(4,s->a,s->b,s->c,s->d,14,p->f48,p->f54);
        func_021FC754(*(char **)((char *)p+i*4),(void *)second,s->value,(void *)first,0x3da0);
    }
    func_021FD170(p->f38,(char *)(q->f8),(void *)107);
    return 1;
}








int func_021DFC88(char *p, struct CodeinArgA *q)
{
    int i;
    for (i = 0; i < 3; i++) {
        if (*(void **)(p + i * 4) != 0) {
            func_021FC734(*(void **)(p + i * 4));
            *(void **)(p + i * 4) = 0;
        }
    }
    for (i = 0; i < 2; i++) {
        if (*(void **)(p + i * 4 + 12) != 0) {
            func_021FB494(*(void **)(p + i * 4 + 12));
            *(void **)(p + i * 4 + 12) = 0;
        }
    }
    func_020409B4(4);
    func_021FBDA4(q->f8, 26);
    return 1;
}







/*
 * lever: A separate result!=3 guard around the three-case switch removes the extra 8-byte dense dispatch (460 to 452 B).
 */
int func_021DFCD4(struct CodeinWorkB *p,struct CodeinArgB *q)
{
    int result=func_021E04C8();
    if(result!=3) {
    switch(result) {
    case 0: {
        u32 x,y;
        Point args;
        func_02035D20(&x,&y);args.x=x;args.y=y;
        func_021FD860((void *)p->f40,1,&args);
        func_020061E4(0x703);
        q->f18=19;
        func_021E03B0(p,q,0);
        func_021FD170(p->f38,(char *)(q->f8),(void *)105);
        p->f50=1;
        return 1;
    }
    case 1: {
        u32 x,y;
        Point args;
        func_02035D20(&x,&y);args.x=x;args.y=y;
        func_021FD860((void *)p->f40,1,&args);
        func_020061E4(0x703);
        q->f14=0xffff;
        func_021E03B0(p,q,1);
        func_021FD170(p->f38,(char *)(q->f8),(void *)106);
        p->f50=2;
        return 1;
    }
    case 2: {
        void *v;
        int a,b;
        u32 x,y;
        Point args;
        v=func_02012944(q->f10);
        a=func_0200856C(v);b=func_02008570(v);
        if(!a && !b) {
            func_021FD170(p->f38,(char *)(q->f8),(void *)120);
            func_020061E4(0x704);
            break;
        }
        func_02035D20(&x,&y);args.x=x;args.y=y;
        func_021FD860((void *)p->f40,1,&args);
        func_020061E4(0x703);
        if(q->f16==255){q->f16=a;q->f17=b;}
        else{q->f16=255;q->f17=255;}
        func_021E03B0(p,q,2);
        return 0;
    }
    }
    }
    {
        u32 x,y;
        if(func_02035D20(&x,&y)) {
            if(func_021FB4B4((unsigned int *)(p->fC),x,y)) {
                Point args;
                args.x=x;args.y=y;
                func_021FD860((void *)p->f40,1,&args);
                p->f50=-1;
                func_021F9BA0((*(void * *)&q->fC));
                return 1;
            }
            if(func_021FB4CC((u32 *)(p->f10),x,y)) {
                if(q->f14!=0xffff || q->f17!=255 || q->f18!=19) {
                    Point args;
                    args.x=x;args.y=y;
                    func_020061E4(0x703);
                    func_021FD860((void *)p->f40,1,&args);
                    p->f50=-1;
                    func_021F9BF4(*(unsigned * *)&q->fC,5);
                    return 1;
                }
                func_020061E4(0x704);
                func_021FD170(p->f38,(char *)(q->f8),(void *)108);
            }
        }
    }
    return 0;
}







int func_021DFE98(struct CodeinWorkB *p,struct CodeinArgA *q)
{
    int first,second,i;
    CfgTpl cfg;
    Triple triple;
    Params params;
    first=func_021FC20C(*(char * *)&q->f8);
    second=func_021FC214(*(char * *)&q->f8);
    func_021FB964((void *)(q->f8),27,p->f54);
    *(Slot_021DB2E0 * *)&p->f14=BMP_MENUWORK_Create(19,p->f54);
    for(i=0;i<19;i++)BMP_MENUWORK_AddMsgItem((Slot_021DB2E0 *)((u32)*(Slot_021DB2E0 * *)&p->f14+i*8),second,i+205,i,p->f54);
    cfg=d_021E3758;
    cfg.words[0]=*(u32 *)&p->f14;cfg.words[1]=19;
    cfg.words[5]=*(u32 *)&q->f8;cfg.words[6]=(*(unsigned int *)&q->f4);
    p->f18=func_021FC8C8((const Config_021DF1DC *)&cfg,p->f54);
    func_02082BCC(&params,0,8);
    func_021FC124((void *)q->f8, 6, (Triple *)&triple);
    params.a=d_021E3728[0].x;params.b=d_021E3728[0].y;params.c=d_021E3728[0].id;params.flag=1;
    (*(void * *)&p->fC)=func_021FB378(&params,d_021E3728[0].file,96,1,q->f4,p->f44,first,second,&triple,p->f54);
    return 1;
}







int func_021DFF78(struct CodeinWorkB *p, struct CodeinArgA *q)
{
    if ((*(void * *)&p->fC)) {
        func_021FB494((*(void * *)&p->fC));
        (*(void * *)&p->fC) = 0;
    }
    func_021FCC80(p->f18);
    p->f18 = 0;
    BMP_MENUWORK_Delete(p->f14);
    p->f14 = 0;
    func_021FBDA4(q->f8, 27);
    func_020409B4(4);
    return 1;
}







int func_021DFFB0(struct CodeinWorkB *p, struct CodeinArgB *q)
{
    int selected, pressed;
    unsigned int x, y;
    func_021FCD0C(p->f18);
    selected = func_021FCDA8(p->f18);
    pressed = func_02035D20(&x, &y);
    pressed &= func_021FB4B4((unsigned int *)(p->fC), x, y);
    if (selected != -1) {
        unsigned int x1, y1;
        Point args;
        func_02035D20(&x1, &y1);
        args.x = x1;
        args.y = y1;
        func_021FD860((void *)p->f40, 1, &args);
        q->f18 = selected;
        func_021E03B0(p, q, 0);
        p->f50 = 0;
        return 1;
    } else if (pressed != 0) {
        unsigned int x2, y2;
        Point args;
        func_02035D20(&x2, &y2);
        args.x = x2;
        args.y = y2;
        func_021FD860((void *)p->f40, 1, &args);
        p->f50 = 0;
        return 1;
    }
    return 0;
}







void func_021E0044(struct CodeinWorkA *p, struct CodeinArgA *q)
{
    p->f1C = func_021FFBD4(func_0200CA1C((*(void * *)&q->f10)), (*(void * *)&q->f8), q->f4, p->f44, q->f0, (*(int *)&p->f3C), p->f40, p->f54);
    func_021FFE5C(p->f1C);
    func_021FFE34(p->f1C);
}







int func_021E0080(struct CodeinWorkA *p)
{
    func_021FFE70((*(void * *)&p->f1C));
    func_021FFC6C((*(void * *)&p->f1C));
    func_020409B4(4);
    return 1;
}






/*
 * lever: Repeat the reset store in both result arms, with return 1 shared after them; hoisting the store removes the branch at 0x021E00C8.
 */
int func_021E009C(struct CodeinWorkB *p, struct CodeinArgB *q)
{
    u16 out;
    int result;
    func_021FFC9C(*(char * *)&p->f1C);
    result = func_021FFE90(*(int * *)&p->f1C, &out);
    if (result) {
        if (result == 2) {
            q->f14 = out;
            func_021E03B0(p, q, 1);
            p->f50 = 0;
        } else {
            p->f50 = 0;
        }
        return 1;
    }
    return 0;
}






int func_021E00D8(struct CodeinWorkB *p,struct CodeinArgA *q)
{
    int first,second,a,b;
    void *v,*text,*data;
    int ws;
    CfgTpl cfg;
    Triple triple;
    Params params;
    first=func_021FC20C(*(char * *)&q->f8);
    second=func_021FC214(*(char * *)&q->f8);
    func_021FB964((void *)(q->f8),28,p->f54);
    text=STRBUF_Create(128,p->f54);
    v=func_02012944((*(void * *)&q->f10));
    a=func_0200856C(v);b=func_02008570(v);
    ws=func_021FC21C(*(char * *)&q->f8);
    data=func_02045EC0((void *)second,125);
    if(!func_02025B64(a))func_0201F048((void *)ws,0,a);
    else func_0201F094((void *)ws,0,a,b);
    func_0201F250((void *)ws,text,data);
    STRBUF_Delete(data);
    *(Slot_021DB2E0 * *)&p->f14=BMP_MENUWORK_Create(1,p->f54);
    BMP_MENUWORK_AddStrItem(*(Slot_021DB2E0 * *)&p->f14,(u32)text,0,p->f54);
    STRBUF_Delete(text);
    cfg=d_021E3780;
    cfg.words[0]=*(u32 *)&p->f14;cfg.words[1]=1;
    cfg.words[5]=*(u32 *)&q->f8;cfg.words[6]=(*(unsigned int *)&q->f4);
    p->f18=func_021FC8C8((const Config_021DF1DC *)&cfg,p->f54);
    func_02082BCC(&params,0,8);
    func_021FC124((void *)q->f8, 6, (Triple *)&triple);
    params.a=d_021E372E[0].x;params.b=d_021E372E[0].y;params.c=d_021E372E[0].id;params.flag=1;
    (*(void * *)&p->fC)=func_021FB378(&params,d_021E372E[0].file,96,1,q->f4,p->f44,first,second,&triple,p->f54);
    return 1;
}






int func_021E0214(struct CodeinWorkB *p, struct CodeinArgA *q)
{
    if ((*(void * *)&p->fC)) {
        func_021FB494((*(void * *)&p->fC));
        (*(void * *)&p->fC) = 0;
    }
    func_021FCC80(p->f18);
    p->f18 = 0;
    BMP_MENUWORK_Delete(p->f14);
    p->f14 = 0;
    func_021FBDA4(q->f8, 28);
    func_020409B4(4);
    return 1;
}






/*
 * trailing: two zero alignment bytes at 0x021E02F6
 */
int func_021E024C(struct CodeinWorkB *p, struct CodeinArgB *q)
{
    int selected, pressed;
    unsigned int x, y;
    func_021FCD0C(p->f18);
    selected = func_021FCDA8(p->f18);
    pressed = func_02035D20(&x, &y);
    pressed &= func_021FB4B4((unsigned int *)(p->fC), x, y);
    if (selected != -1) {
        unsigned int x1, y1;
        Point args;
        void *v;
        int a;
        func_02035D20(&x1, &y1);
        args.x = x1;
        args.y = y1;
        func_021FD860((void *)p->f40, 1, &args);
        v = func_02012944(q->f10);
        a = func_0200856C(v);
        q->f17 = func_02008570(v);
        q->f16 = a;
        func_021E03B0(p, q, 2);
        p->f50 = 0;
        return 1;
    } else if (pressed != 0) {
        unsigned int x2, y2;
        Point args;
        func_02035D20(&x2, &y2);
        args.x = x2;
        args.y = y2;
        func_021FD860((void *)p->f40, 1, &args);
        p->f50 = 0;
        return 1;
    }
    return 0;
}






void func_021E02F8(struct CodeinWorkA *p, int *q)
{
    int first, second, i;
    const Record *r;
    first = func_021FC20C((char *)q[2]);
    second = func_021FC214((char *)q[2]);
    func_021FB964((void *)q[2], 25, p->f54);
    for (i = 0; i < 6; i++) {
        r = &d_021E37D8[i];
        *(void **)((char *)p + i * 4 + 0x20) = func_021FC6A4(1, r->a, r->b, r->c, r->d, 14, p->f48, p->f54);
        func_021FC868(*(void **)((char *)p + i * 4 + 0x20), 0, 1, 0);
        func_021FC754(*(void **)((char *)p + i * 4 + 0x20), (void *)second, (void *)r->value, (void *)first, 15776);
    }
}






/*
 * extent: final two bytes are alignment padding.
 */
void func_021E037C(char *p,struct CodeinArgA *q){int i;for(i=0;i<6;i++){if(*(void **)(p+i*4+0x20)){func_021FC734(*(void **)(p+i*4+0x20));*(void **)(p+i*4+0x20)=0;}}func_021FBDA4(q->f8,25);func_020409B4(1);}






void func_021E03B0(struct CodeinWorkB *p,struct CodeinArgB *q,int mode)
{
    int first,second,ws;
    void *data,*text;
    first=func_021FC20C(*(char * *)&q->f8);
    second=func_021FC214(*(char * *)&q->f8);
    switch(mode) {
    case 0:
        if(q->f18!=19)func_021FC754(p->f24,(void *)second,(void *)(q->f18+205),(void *)first,0x3da0);
        else func_021FC754(p->f24,(void *)second,(void *)117,(void *)first,0x3da0);
        return;
    case 1:
        if(q->f14!=0xffff)func_021FC754(p->f2C,(void *)gSpeciesNameBank,(void *)(u32)q->f14,(void *)first,0x3da0);
        else func_021FC754(p->f2C,(void *)second,(void *)117,(void *)first,0x3da0);
        return;
    case 2:
        if(q->f16==255 && q->f17==255) {
            func_021FC754(p->f34,(void *)second,(void *)117,(void *)first,0x3da0);
            return;
        }
        ws=func_021FC21C(*(char * *)&q->f8);
        data=func_02045EC0((void *)second,24);
        text=STRBUF_Create(128,p->f54);
        if(!func_02025B64(q->f16))func_0201F048((void *)ws,0,q->f16);
        else func_0201F094((void *)ws,0,q->f16,q->f17);
        func_0201F250((void *)ws,text,data);
        func_021FC7C4(p->f34,text,(void *)first,0x3da0);
        STRBUF_Delete(data);STRBUF_Delete(text);
        break;
    }
}







/*
 * Hit-test a point against a table of three rectangles; returns the index
 * of the first hit, or 3 when none (or when no point is available).
 */
int func_021E04C8(void)
{
    unsigned int x, y;
    int i;

    if (func_02035D20(&x, &y)) {
        for (i = 0; i < 3; i++) {
            const Rect *r = &g_021E3808[i];
            if (x - r->x0 <= r->x1 - r->x0 && y - r->y0 <= r->y1 - r->y0) {
                return i;
            }
        }
    }
    return 3;
}






/*
 * extent: 021E05C2 alignment padding.
 */
int func_021E050C(void *task, int unused, struct CodeinArgA *q)
{
    struct Data_021DF388 *p;
    int entries[3];
    func_021FC20C((char *)(q->f8));
    func_021FC214(*(char * *)&q->f8);
    p = PROCSYS_AllocProcWork(task, 24, func_021F9B9C(q->fC));
    func_02082BCC(p, 0, 24);
    p->heap = func_021F9B9C(q->fC);
    func_021FB964((void *)(q->f8), 29, p->heap);
    func_021FBE54(*(char * *)&q->f8, 11, p->heap);
    func_021FBE54(*(char * *)&q->f8, 12, p->heap);
    func_021FBE54(*(char * *)&q->f8, 6, p->heap);
    p->e = func_021FD760((unsigned int)((*(void * *)&q->f4)), (char *)(q->f8), 1, p->heap);
    entries[0] = 2;
    entries[1] = 5;
    entries[2] = 5;
    p->a = func_021E07A4(p->heap, 12, (*(void * *)&q->f4), (void *)(q->f8), p->e, entries);
    p->b = func_021E06D0(p->a, p->heap);
    p->d = (void *)func_0201C440((void *)p->heap);
    p->c = func_021FD12C(q->f8, p->d, p->heap);
    func_021FD170(p->c, (char *)(q->f8), (void *)104);
    return 1;
}






/*
 * extent: 021E0616 alignment padding; next owned function starts 021E0618.
 */
int func_021E05C4(void *a, int unused, int *q, void **p)
{
    func_021FD15C((void *)((int)p[2]), q[2]);
    func_021E0774(p[1]);
    func_021E0808(p[0]);
    func_0201C4C0(p[3]);
    func_021FD820(p[5]);
    func_021FBDA4(q[2], 29);
    func_021FC0C8((char *)q[2], 6);
    func_021FC0C8((char *)q[2], 12);
    func_021FC0C8((char *)q[2], 11);
    func_020315D4(a);
    return 1;
}






/*
 * extent: 021E06CE alignment padding.
 */
int func_021E0618(int unused, int *state, int *q, int *p)
{
    switch (*state) {
    case 0:
        func_021FE784(q[0], 2, 3, 0);
        *state = 1;
        break;
    case 1:
        if (func_021FE7B0((int *)q[0])) *state = 2;
        break;
    case 2:
        func_021E0754((char *)p[1]);
        switch (func_021E075C((char *)p[1])) {
        case 1: func_021F9BA0((unsigned int *)q[3]); *state = 3; break;
        case 2: ((struct CodeinArgD *)q)->f10 = func_021E0764((char *)p[1]); func_021F9BF4((unsigned int *)q[3], 2); *state = 3; break;
        }
        break;
    case 3:
        func_021FE784(q[0], 2, 3, 1);
        *state = 4;
        break;
    case 4:
        if (func_021FE7B0((int *)q[0])) *state = 5;
        break;
    case 5: return 1;
    }
    if (p[2]) func_021FD1BC((void *)p[2]);
    PRINTSYS_QUE_Main((struct PrintSys *)p[3]);
    func_021FD854((char *)p[5]);
    return 0;
}



/*
 * extent: 0754 tail-call stub; 075C state getter; 0764 64-bit getter; 0772 padding.
 */
char *func_021E06D0(const CfgTpl *src, u16 heap)
{
    char *p;
    p = func_02030734(heap, 0x368, 0, d_021E3968, 56);
    func_02082BCC(p, 0, 0x368);
    *(CfgTpl *)(p + 0x324) = *src;
    ((struct CodeinWorkA *)p)->f34C = heap;
    (*(int *)&((struct CodeinWorkA *)p)->f25C) = src->words[7];
    ((struct CodeinWorkA *)p)->f310 = func_021FC20C((char *)src->words[8]);
    ((struct CodeinWorkA *)p)->f258 = func_020490F4(59, ((struct CodeinWorkA *)p)->f34C);
    func_021E1244((State_021E111C *)p);
    func_021E1910(p);
    ((struct CodeinWorkA *)p)->f314 = func_020056A0(func_021E083C, p, 16);
    return p;
}



void func_021E0754(char *p)
{
    func_021E16E4(p);
}



int func_021E075C(char *p)
{
    return ((struct CodeinWorkA *)p)->f350;
}



u64 func_021E0764(char *p)
{
    return ((struct CodeinWorkA *)p)->f360;
}



void func_021E0774(struct CodeinWorkA *p){func_02030EAC(p->f314);func_021E08E4(p);ARC_TOOL_DeleteHandle(p->f258);BUTTON_MAN_Delete(p->f294);func_020307B0(p);}



struct Object *func_021E07A4(int heap, int n, void *a, void *b, void *c, int *entries)
{
    int i;
    struct Object *p;
    p = func_02030734((u16)heap, 40, 0, d_021E3968, 192);
    p->a = a;
    p->b = b;
    p->capacity = n;
    p->vector = STRBUF_Create(n + 1, heap);
    p->c = c;
    for (i = 0; i < 3; i++) p->entries[i] = entries[i];
    p->entries[i] = entries[i - 1];
    return p;
}



/*
 * extent: existing matched callback 021E083C and its alignment follow the pool.
 */
void func_021E0808(struct CodeinWorkB *p){if(!p->f18)func_02034714(d_021E3974,0,d_021E3974);if(!p)func_02034714(d_021E3974,0,d_021E3974);STRBUF_Delete(p->f18);func_020307B0(p);}



/*
 * leaf: empty callback solely blocks owned constructor 021E06D0; parent cleared.
 * extent: bx lr at 083C; 083E alignment; existing owned 0840 follows.
 */
void func_021E083C(void)
{
}



void func_021E0840(char *p)
{
    struct Triple t;
    if (!func_021FC124(((struct CodeinWorkA *)p)->f344, 11, &t)) func_02034714(d_021E3978, 0, d_021E3978);
    ((struct CodeinWorkA *)p)->f260 = t.c;
    ((struct CodeinWorkA *)p)->f26C = t.b;
    ((struct CodeinWorkA *)p)->f284 = t.a;
    if (!func_021FC124(((struct CodeinWorkA *)p)->f344, 12, &t)) func_02034714(d_021E3978, 0, d_021E3978);
    ((struct CodeinWorkA *)p)->f268 = t.c;
    ((struct CodeinWorkA *)p)->f274 = t.b;
    ((struct CodeinWorkA *)p)->f28C = t.a;
    if (!func_021FC124(((struct CodeinWorkA *)p)->f344, 6, &t)) func_02034714(d_021E3978, 0, d_021E3978);
    *(int *)&((struct CodeinWorkA *)p)->f264 = t.c;
    *(int *)&((struct CodeinWorkA *)p)->f270 = t.b;
    *(int *)&((struct CodeinWorkA *)p)->f288 = t.a;
}



/*
 * extent: 021E0952 alignment padding.
 */
void func_021E08E4(struct CodeinWorkA *p)
{
    int i;
    for (i = 0; i < p->f23C; i++) CLACT_DeleteActor(*(void **)((char *)p + i * 28 + 12));
    for (i = 0; i < 2; i++) {
        CLACT_DeleteActor(*(void **)((char *)p + i * 28 + 0x15c));
        CLACT_DeleteActor(*(void **)((char *)p + i * 28 + 0x1e8));
    }
    for (i = 0; i < 3; i++) CLACT_DeleteActor(*(void **)((char *)p + i * 28 + 0x194));
    func_021E10BC(p);
}



/*
 * lever: The explicit entry guard encloses a do-while; a for adds a second entry test (308 B DIFF to 306 B EXACT*).
 * trailing: 021E0A86..021E0A88 is two zero alignment bytes.
 * abi: 0204B294 caller uses returned r0 despite callee's void spelling; fifth payload remains its u32 address word.
 * note 2026-10-05 (wave D9r lane 131): removed the 7 dead first assignments
 * (`heapA=0x25c;` before `heapA=0x34c;`; `aA=0x25c;` before `aA=0x26c;` and
 * 5 more). Game code has no line table, so these were stand-ins. The plain
 * single assignment gives EXACT* in --lang c99 and --lang c: the output
 * bytes do not change. Older text in this header that asks for the double
 * assignment is superseded.
 */
void func_021E0954(char *p)
{
    int i,special,normal,base;
    u32 owner;
    int heapA,aA,bA,cA,heapB,aB,bB,cB,countOffset,recordOffset;
    Params params;
    normal=0;
    base=0x25c;
    owner=*(u32 *)(p+base);
    params.a=normal;params.b=normal;params.c=normal;params.flag=10;params.pad=normal;
    special=0;i=0;
    if(*(int *)(p+base-0x20)+2>0) {
        heapA=0x34c;
        aA=0x26c;
        bA=0x260;
        cA=0x284;
        heapB=0x34c;
        aB=0x26c;
        bB=0x260;
        cB=0x284;
        countOffset=0x23c;
        recordOffset=0x150;
        do {
            char *q;
            q=p+special*28;
            if(i==*(int *)(q+recordOffset)+special+1) {
                void *obj;
                params.a=i*8+76;params.b=24;params.c=22;
                obj=CLACT_CreateActor((void *)owner,*(u32 *)(p+aB),*(u32 *)(p+bB),*(u32 *)(p+cB),&params,1,*(u16 *)(p+heapB));
                ((struct CodeinArgA *)q)->f15C=obj;func_0204B688(obj,1);
                special++;
            } else {
                void *obj;
                params.a=i*8+76;params.b=24;
                q=p+normal*28;
                params.c=func_021E0E40(((struct CodeinArgA *)q)->f0,((struct CodeinArgA *)q)->f8);
                obj=CLACT_CreateActor((void *)owner,*(u32 *)(p+aA),*(u32 *)(p+bA),*(u32 *)(p+cA),&params,1,*(u16 *)(p+heapA));
                ((struct CodeinArgA *)q)->fC=obj;func_0204B688(obj,1);
                normal++;
            }
            i++;
        } while(i<*(int *)(p+countOffset)+2);
    }
}



/*
 * abi: 0204B294 r0 consumed after call; pointer request passed as the unchanged u32 fifth payload.
 */
void func_021E0A88(char *p)
{
    int base,zero;
    u32 owner;
    Params params;
    base=0x25c;owner=*(u32 *)(p+base);zero=0;
    params.a=zero;params.b=zero;params.c=zero;params.flag=zero;params.pad=zero;
    *(u32 *)(p+base-0xc8)=(u32)CLACT_CreateActor((void *)owner,*(u32 *)(p+base+0x18),*(u32 *)(p+base+0xc),*(u32 *)(p+base+0x30),&params,1,*(u16 *)(p+base+0xf0));
    func_0204B688(*(void **)(p+base-0xc8),1);
    *(u32 *)(p+base-0xac)=(u32)CLACT_CreateActor((void *)owner,*(u32 *)(p+base+0x18),*(u32 *)(p+base+0xc),*(u32 *)(p+base+0x30),&params,1,*(u16 *)(p+base+0xf0));
    func_0204B688(*(void **)(p+base-0xac),1);
    *(u32 *)(p+base-0x90)=(u32)CLACT_CreateActor((void *)owner,*(u32 *)(p+base+0x18),*(u32 *)(p+base+0xc),*(u32 *)(p+base+0x30),&params,1,*(u16 *)(p+base+0xf0));
    func_0204B688(*(void **)(p+base-0x90),1);
    func_021E0D00(p,0);
    CLACT_SetActorAnimSeq(*(void **)(p+base-0xc8),0);func_0204B92C(*(void **)(p+base-0xc8),1);
    *(u16 *)(p+base-0xa4)=zero;*(u16 *)(p+base-0xa2)=zero;*(u32 *)(p+base-0xb8)=1;
    func_021E0D38((struct Coordinates *)p,0);
    CLACT_SetActorAnimSeq(*(void **)(p+base-0xac),*(u32 *)(p+base-0xb8));
    func_0204B92C(*(void **)(p+base-0xac),1);func_0204B688(*(void **)(p+base-0xac),1);
    *(u16 *)(p+base-0x88)=zero;*(u16 *)(p+base-0x86)=zero;*(u32 *)(p+base-0x9c)=1;
    func_021E0D38((struct Coordinates *)p,zero);
    CLACT_SetActorAnimSeq(*(void **)(p+base-0x90),*(u32 *)(p+base-0x9c));
    func_0204B688(*(void **)(p+base-0x90),1);func_0204B92C(*(void **)(p+base-0x90),1);
    func_021E0CE8(p,1,zero);func_021E0CE8(p,2,zero);
}



/*
 * Caller evidence: 0204B294 leaves its forwarded return word live in r0; consumed by store and 0204B688 here.
 */
void func_021E0C04(char *p) {
    struct PosParams pos;
    u32 manager=*(u32 *)&((struct CodeinWorkA *)p)->f25C;
    pos.a=0;pos.b=0;pos.z=0;pos.mode=10;pos.flag=0;
    *(u32 *)&((struct CodeinWorkA *)p)->f1E8=(u32)CLACT_CreateActor((void *)manager,((struct CodeinWorkA *)p)->f270,((struct CodeinWorkA *)p)->f264,((struct CodeinWorkA *)p)->f288,&pos.a,1,((struct CodeinWorkA *)p)->f34C);
    func_0204B688(((struct CodeinWorkA *)p)->f1E8,1);
    pos.z=1;
    *(u32 *)&((struct CodeinWorkA *)p)->f204=(u32)CLACT_CreateActor((void *)manager,((struct CodeinWorkA *)p)->f270,((struct CodeinWorkA *)p)->f264,((struct CodeinWorkA *)p)->f288,&pos.a,1,((struct CodeinWorkA *)p)->f34C);
    func_0204B688(((struct CodeinWorkA *)p)->f204,1);
    pos.x=((struct CodeinWorkA *)p)->f2F2;pos.y=((struct CodeinWorkA *)p)->f2F0+16;
    func_0204B404(((struct CodeinWorkA *)p)->f1E8,(const struct Vec2 *)(&pos.x),1);
    CLACT_SetActorAnimSeq(((struct CodeinWorkA *)p)->f1E8,0);
    pos.x=((struct CodeinWorkA *)p)->f2F6;pos.y=((struct CodeinWorkA *)p)->f2F4+16;
    func_0204B404(((struct CodeinWorkA *)p)->f204,(const struct Vec2 *)(&pos.x),1);
    CLACT_SetActorAnimSeq(((struct CodeinWorkA *)p)->f204,1);
}




void func_021E0CE8(char *p, int index, int a2)
{
    func_0204B3DC((struct Obj *)*(int *)(p + index * 0x1c + 0x194), (unsigned int)a2);
}



void func_021E0D00(char *p,int i){short pos[2];void *obj;obj=*(void **)(p+i*28+12);((struct CodeinWorkA *)p)->f188=i;CLACT_GetActorSurfacePos(obj,(struct PtS *)pos,1);pos[1]+=16;func_0204B404(((struct CodeinWorkA *)p)->f194,(const struct Vec2 *)pos,1);}



/*
 * extent: 021E0D8E alignment padding.
 */
void func_021E0D38(struct Coordinates *p, int index)
{
    int width = p->rect[index + 12][1] - p->rect[index + 12][0];
    int height = p->rect[index + 12][3] - p->rect[index + 12][2];
    s16 pos[2];
    pos[0] = height / 2 + p->rect[index + 12][2];
    pos[1] = width / 2 + p->rect[index + 12][0];
    func_0204B404(((struct CodeinWorkA *)p)->f1B0, (const struct Vec2 *)pos, 1);
    CLACT_SetActorAnimFrame(((struct CodeinWorkA *)p)->f1B0, 0);
}



/*
 * extent: 021E0E3E alignment padding.
 */
void func_021E0D90(char *p)
{
    int i, state;
    for (i = 1; i < 3; i++) {
        state = CLACT_GetActorAnimSeq(*(void **)(p + i * 28 + 0x194));
        if (state == 3) {
            if (!CLACT_IsActorAnimActive(*(void **)(p + i * 28 + 0x194))) {
                CLACT_SetActorAnimSeq(*(void **)(p + i * 28 + 0x194), *(int *)(p + i * 28 + 0x188));
                if (((struct CodeinWorkA *)p)->f2FC == 1) func_021E0CE8(p, 1, 0);
                else func_021E0CE8(p, 1, 1);
                func_021E0CE8(p, 2, 0);
            }
        } else {
            if (state != *(int *)(p + i * 28 + 0x188)) CLACT_SetActorAnimSeq(*(void **)(p + i * 28 + 0x194), *(int *)(p + i * 28 + 0x188));
            if (CLACT_GetActorAnimSeq(*(void **)(p + i * 28 + 0x194)) != 3) {
                if (((struct CodeinWorkA *)p)->f2FC == 1) func_021E0CE8(p, 1, 0);
                else func_021E0CE8(p, 1, 1);
            }
        }
    }
}



int func_021E0E40(int a, int b) { int n=0; if(b==0)n=11; return n+a; }



void func_021E0E4C(char *p)
{
    int i;
    for (i = 0; i < ((struct CodeinWorkA *)p)->f23C; i++) {
        if (i >= ((struct CodeinWorkA *)p)->f248 && i < ((struct CodeinWorkA *)p)->f24C)
            *(int *)(p + i * 28 + 8) = 1;
        else
            *(int *)(p + i * 28 + 8) = 0;
    }
}



void func_021E0E90(char *p,int animated) {
    int i,group;
    s16 pos;
    char *record,*special;
    Coords coords;
    pos=*(s16 *)((u32)p+((struct CodeinWorkA *)p)->f240*2+0x214);
    group=0;
    for(i=0;i<((struct CodeinWorkA *)p)->f23C;i++){
        if(i>=((struct CodeinWorkA *)p)->f248&&i<((struct CodeinWorkA *)p)->f24C){
            if(i==((struct CodeinWorkA *)p)->f248)pos+=20;else pos+=32;
        }else{
            if(i==0)pos+=20;else pos+=8;
        }
        record=(char *)((u32)p+i*28);
        CLACT_GetActorSurfacePos(((struct CodeinRecordA *)record)->fC,(struct PtS *)&coords.x,1);
        if(animated==0){
            coords.x=pos;
            func_0204B404(((struct CodeinRecordA *)record)->fC,(const struct Vec2 *)(&coords.x),1);
        }else{
            ((struct CodeinRecordA *)record)->f14=(pos-coords.x)/4;
            ((struct CodeinRecordA *)record)->f16=0;
            ((struct CodeinRecordA *)record)->f18=4;
            ((struct CodeinRecordA *)record)->f19=0;
        }
        special=(char *)((u32)p+group*28);
        if(i==((struct CodeinSpecialA *)special)->f150&&group!=2){
            CLACT_GetActorSurfacePos(((struct CodeinSpecialA *)special)->f15C,(struct PtS *)&coords.a,1);
            if(((struct CodeinWorkA *)p)->f248==((struct CodeinWorkA *)p)->f24C)pos+=8;
            else {
                if(i>((struct CodeinWorkA *)p)->f248&&i<((struct CodeinWorkA *)p)->f24C)pos+=20;
                else pos+=8;
            }
            if(animated==0){
                coords.a=pos;
                func_0204B404(((struct CodeinSpecialA *)special)->f15C,(const struct Vec2 *)(&coords.a),1);
            }else{
                ((struct CodeinSpecialA *)special)->f164=(pos-coords.a)/4;
                ((struct CodeinSpecialA *)special)->f166=0;
                ((struct CodeinSpecialA *)special)->f168=4;
            }
            group++;
        }
    }
}



void func_021E1008(char *p)
{
    int i, x, y;
    s16 pos[2];
    for (i = 0; i < ((struct CodeinWorkA *)p)->f23C; i++) {
        if (i >= ((struct CodeinWorkA *)p)->f248 && i < ((struct CodeinWorkA *)p)->f24C) {
            x = 16;
            y = 16;
        } else {
            x = 4;
            y = 8;
        }
        CLACT_GetActorSurfacePos(*(void **)(p + i * 28 + 12), (struct PtS *)pos, 1);
        (*(u8 **)(p + i * 28 + 16))[0] = pos[1] - y;
        (*(u8 **)(p + i * 28 + 16))[2] = pos[0] - x;
        (*(u8 **)(p + i * 28 + 16))[1] = pos[1] + y;
        (*(u8 **)(p + i * 28 + 16))[3] = pos[0] + x;
    }
}




void func_021E10A0(char *p)
{
    ((struct CodeinWorkA *)p)->f300 =
        BMP_OAM_CreateSys(((struct CodeinWorkA *)p)->f34C, ((struct CodeinWorkA *)p)->f25C);
}



void func_021E10BC(struct CodeinWorkA *p){ BMP_OAM_Delete(*(struct Grid * *)&p->f304); BMP_OAM_Delete(*(struct Grid * *)&p->f308); BMP_OAM_DeleteSys(p->f300); }




void func_021E10DC(char *p)
{
    ARC_TOOL_DeleteHandle(func_020490F4(0x17, ((struct CodeinWorkA *)p)->f34C));
}



void func_021E10F4(char *p){ func_021E10DC(p);func_021E111C((const Object *)p,0,32,8,0);func_021E111C((const Object *)p,1,32,8,0); }







/*
 * lever: form slot=&out[index] before the constructor call and store/reload through slot. The direct out[index] spelling sank the output base and left 15 bytes different.
 */
void func_021E111C(const Object *object,Index index,int x,int y,int unused)
{
    char *p=(char *)object;
    int source,handle,obj;
    u8 xx,yy;
    struct Grid **slots;
    Descriptor_021E111C desc;
    source=func_021FC214(*(char * *)&((struct CodeinWorkA *)p)->f344);
    source=(int)func_02045EC0((struct MsgBank *)source,d_021E3850[index]);
    handle=(int)BMP_Create(10,2,32,((struct CodeinWorkA *)p)->f34C);
    PRINTSYS_Print((void *)handle,1,0,(void *)source,(void *)(((struct CodeinWorkA *)p)->f310));
    xx=((u8 *)(p+0x29a))[(index+22)*4];
    yy=((u8 *)(p+0x298))[(index+22)*4];
    desc.handle=(void *)handle;
    desc.x=xx+x;
    desc.y=yy+y;
    desc.data=(*(int *)&((struct CodeinWorkA *)p)->f264);
    desc.zero=0;
    desc.a=0;
    desc.b=0;
    desc.c=1;
    desc.d=1;
    {
        struct Grid **out=(struct Grid **)(char *)object->f304;
        struct Grid **slot;
        struct Grid *grid;
        slot=&out[index];
        grid=BMP_OAM_Create(object->f300,(const struct Param *)(&desc));
        *slot=grid;
        BMP_OAM_UploadChars((struct Obj *)((int)grid));
        BMP_OAM_SetObjMode((u8 *)((int)*slot),1);
    }
    BMP_Delete((struct Obj020437AC *)handle);
    STRBUF_Delete((struct U16Vec *)source);
}







/*
 * Extent remainder: zero alignment halfword at 021E1242.
 */
void func_021E11D0(char *p,int state)
{
    ((struct CodeinWorkA *)p)->f244=((struct CodeinWorkA *)p)->f240;
    ((struct CodeinWorkA *)p)->f240=state;
    ((struct CodeinWorkA *)p)->f248=0;
    ((struct CodeinWorkA *)p)->f24C=0;
    ((struct CodeinWorkA *)p)->f250=0;
    ((struct CodeinWorkA *)p)->f254=0;
    if (state) {
        ((struct CodeinWorkA *)p)->f248=*(u16 *)(p+(state-1)*4+0x21c);
        ((struct CodeinWorkA *)p)->f24C=*(u16 *)(p+(state-1)*4+0x21e);
    }
    if (((struct CodeinWorkA *)p)->f244) {
        ((struct CodeinWorkA *)p)->f250=*(u16 *)(p+(((struct CodeinWorkA *)p)->f244-1)*4+0x21c);
        ((struct CodeinWorkA *)p)->f254=*(u16 *)(p+(((struct CodeinWorkA *)p)->f244-1)*4+0x21e);
    }
}







/*
 * 2026-10-05 (wave P7 lane V7, pengy share): EXACT in c99 and c. The older DIFF28 draft (see docs/notes) closed with two
 * changes. (1) The row index is a block-local initialised BEFORE the table copy (int row = 0, then the const Table copy):
 * the zero then lives across the copy and the copy takes r5/r3 as in the original. (2) The count row pointer of the last
 * loop is a named State_021E111C pointer local declared before j (cnt = p + group * 4), which gives j r3
 * and the row pointer r2. Original reads: p[0x2FC] = 1; halfword offsets; a stray store at 0x21A reading row[i - 1] after the
 * copy loop (reproduced as in the listing, probably an off-by-one in the original); no hidden callee arguments.
 */
void func_021E1244(State_021E111C *p)
{
  int i;
  int sum;
  int prefix;
  int group;
  int k;
  State_021E111C *cnt;
  int j;
  u16 truncated;
  char *tmp;
  *((int *) (((char *) p) + 0x2FC)) = 1;
  *((u16 *) (((char *) p) + 0x21C)) = 0;
  sum = *((int *) (((char *) p) + 0x328));
  truncated = sum;
  *((u16 *) (((char *) p) + 0x21E)) = truncated;
  *((u16 *) (((char *) p) + 0x220)) = truncated;
  sum += *((int *) (((char *) p) + 0x32C));
  tmp = ((char *) p) + 0x222;
  truncated = sum;
  *((u16 *) tmp) = truncated;
  *((u16 *) (((char *) p) + 0x224)) = truncated;
  sum = (*((int *) (((char *) p) + 0x330))) + ((int) sum);
  *((u16 *) (((char *) p) + 0x226)) = sum;
  func_021E11D0((char *) p, 1);
  for (i = 0; i < 3; i++)
    *((int *) (((char *) p) + 0x23C)) += *((int *) ((((u32) p) + (i * 4)) + 0x328));

  {
    int row = 0;
    const Table_021E1244 table = d_021E3868;
    if ((*((int *) (((char *) p) + 0x328))) != 4)
      row = 1;
    for (i = 0; i < 3; i++)
      *((u16 *) ((((u32) p) + (i * 2)) + 0x214)) = table.row[row].v[i];

    *((u16 *) ((((u32) p) + (i * 2)) + 0x214)) = table.row[row].v[i - 1];
    prefix = 0;
    for (group = 0; group < 2; group++)
    {
      prefix += *((int *) ((((u32) p) + (group * 4)) + 0x328));
      *((int *) ((((u32) p) + (group * 28)) + 0x150)) = prefix - 1;
    }

    group = 0;
    j = 0;
    do
    {
      cnt = (State_021E111C *) (((u32) p) + (group * 4));
      for (k = 0; k < cnt->count; k++)
      {
        *((int *) ((((u32) p) + (j * 28)) + 4)) = group + 1;
        j++;
      }

      group++;
    }
    while (j < (*((int *) (((char *) p) + 0x23C))));
  }
}








void func_021E1374(char *p, int v)
{
    ((struct CodeinWorkA *)p)->f22C = v;
    ((struct CodeinWorkA *)p)->f230 = 0;
    ((struct CodeinWorkA *)p)->f234 = 0;
    ((struct CodeinWorkA *)p)->f238 = 0;
}







/*
 * Follower: 021E13D4 return-one stub, after 021E13D2 alignment.
 */
int func_021E138C(char *p)
{
    func_021E0840(p);
    func_021E0E4C(p);
    func_021E0954(p);
    func_021E0E90(p,0);
    func_021E0A88(p);
    func_021E0C04(p);
    func_021E1008(p);
    func_021E10A0(p);
    func_021E10F4(p);
    func_021E1374(p,1);
    return 0;
}







int func_021E13D4(void)
{
    return 1;
}







s32 func_021E13D8(char *p)
{
    if (*(s32 *)(p + 0x234) == 0) {
        (*(s32 *)(p + 0x234))++;
    } else {
        func_021E1BA8(p);
        BUTTON_MAN_UpdateSlots(*(void **)(p + 0x294));
    }
    return 0;
}







int func_021E13FC(char *p) {
    int i,factor,selected;
    char *record;
    Point scale;
    Coords coords;
    switch(((struct CodeinWorkA *)p)->f234){
    case 0:
        func_021E0CE8(p,0,0);
        for(i=0;i<((struct CodeinWorkA *)p)->f23C;i++){
            record=(char *)((u32)p+i*28);
            if(((struct CodeinRecordA *)record)->f18!=0){
                CLACT_GetActorSurfacePos(((struct CodeinRecordA *)record)->fC,(struct PtS *)&coords.x,1);
                coords.x+=((struct CodeinRecordA *)record)->f14;
                coords.y+=((struct CodeinRecordA *)record)->f16;
                func_0204B404(((struct CodeinRecordA *)record)->fC,(const struct Vec2 *)(&coords.x),1);
                --((struct CodeinRecordA *)record)->f18;
                if(i>=((struct CodeinWorkA *)p)->f248&&i<((struct CodeinWorkA *)p)->f24C){
                    factor=*(int *)((u32)d_021E3998+((struct CodeinRecordA *)record)->f19*4);
                    scale.x=factor;scale.y=factor;
                    CLACT_SetActorScale(((struct CodeinRecordA *)record)->fC,&scale);
                    ++((struct CodeinRecordA *)record)->f19;
                }
                if(i>=((struct CodeinWorkA *)p)->f250&&i<((struct CodeinWorkA *)p)->f254){
                    factor=*(int *)((u32)d_021E397C+((struct CodeinRecordA *)record)->f19*4);
                    scale.x=factor;scale.y=factor;
                    CLACT_SetActorScale(((struct CodeinRecordA *)record)->fC,&scale);
                    ++((struct CodeinRecordA *)record)->f19;
                }
            }
        }
        for(i=0;i<2;i++){
            record=(char *)((u32)p+i*28);
            if(((struct CodeinRecordA *)record)->f168!=0){
                CLACT_GetActorSurfacePos(((struct CodeinRecordA *)record)->f15C,(struct PtS *)&coords.a,1);
                coords.a+=((struct CodeinRecordA *)record)->f164;
                coords.b+=((struct CodeinRecordA *)record)->f166;
                func_0204B404(((struct CodeinRecordA *)record)->f15C,(const struct Vec2 *)(&coords.a),1);
                --((struct CodeinRecordA *)record)->f168;
            }
        }
        if(((struct CodeinWorkA *)p)->f18==0){
            for(i=((struct CodeinWorkA *)p)->f248;i<((struct CodeinWorkA *)p)->f24C;i++){
                record=(char *)((u32)p+i*28);
                CLACT_SetActorAnimSeq(((struct CodeinRecordA *)record)->fC,func_021E0E40(((struct CodeinRecordA *)record)->f0,((struct CodeinRecordA *)record)->f8));
            }
            for(i=((struct CodeinWorkA *)p)->f250;i<((struct CodeinWorkA *)p)->f254;i++){
                record=(char *)((u32)p+i*28);
                CLACT_SetActorAnimSeq(((struct CodeinRecordA *)record)->fC,func_021E0E40(((struct CodeinRecordA *)record)->f0,((struct CodeinRecordA *)record)->f8));
            }
            ++((struct CodeinWorkA *)p)->f234;
        }
        ++((struct CodeinWorkA *)p)->f238;
        break;
    case 1:
        for(i=((struct CodeinWorkA *)p)->f248;i<((struct CodeinWorkA *)p)->f24C;i++){
            record=(char *)((u32)p+i*28);
            if(((struct CodeinRecordA *)record)->f19!=6){
                factor=*(int *)((u32)d_021E3998+((struct CodeinRecordA *)record)->f19*4);
                scale.x=factor;scale.y=factor;
                CLACT_SetActorScale(((struct CodeinRecordA *)record)->fC,&scale);
                ++((struct CodeinRecordA *)record)->f19;
            }
        }
        for(i=((struct CodeinWorkA *)p)->f250;i<((struct CodeinWorkA *)p)->f254;i++){
            record=(char *)((u32)p+i*28);
            if(((struct CodeinRecordA *)record)->f19!=6){
                factor=*(int *)((u32)d_021E397C+((struct CodeinRecordA *)record)->f19*4);
                scale.x=factor;scale.y=factor;
                CLACT_SetActorScale(((struct CodeinRecordA *)record)->fC,&scale);
                ++((struct CodeinRecordA *)record)->f19;
            }
        }
        if(++((struct CodeinWorkA *)p)->f238==6)++((struct CodeinWorkA *)p)->f234;
        break;
    default:
        func_021E1008(p);
        if(((struct CodeinWorkA *)p)->f320==0)selected=func_021E1C14(p,((struct CodeinWorkA *)p)->f31C);
        else selected=func_021E1C44(p,((struct CodeinWorkA *)p)->f31C);
        func_021E0D00(p,selected);
        if(((struct CodeinWorkA *)p)->f240!=0)func_021E0CE8(p,0,1);
        func_021E1C00(p);
        func_021E1374(p,1);
        break;
    }
    return 0;
}







extern int (*const d_021E3858[])(char *);







int func_021E16E4(char *p){ int r=d_021E3858[*(int *)(p+0x22c)](p); func_021E0D90(p); return r; }







/*
 * Matching: named digit load and byte-field address, with group before used in declaration order, preserve the original loop registers.
 */
void func_021E1708(char *p)
{
  u32 group = 0;
  u32 i;
  int used = 0;
  int digit;
  void *text;
  char *record;
  u64 *acc;
  u64 product;
  u32 tmp;
  char *tmp1;
  text = STRBUF_Create(100, *((u16 *) (p + 0x34C)));
  tmp1 = p + 0x210;
  *((int *) (p + 0x1F8)) = 1;
  *((u8 *) tmp1) = 0;
  *((int *) (p + 0x354)) = 0;
  *((int *) (p + 0x358)) = 0;
  *((int *) (p + 0x35C)) = 0;
  *((u32 *) (p + 0x360)) = 0;
  *((u32 *) (p + 0x364)) = 0;
  i = 0;
  if (((int) i) < (*((int *) (p + 0x23C))))
  {
    acc = (u64 *) (p + 0x360);
    do
    {
      record = (char *) (((u32) p) + (i * 28));
      if ((*((int *) record)) == 0)
      {
        *((int *) record) = 1;
        CLACT_SetActorAnimSeq(*((void **) (record + 12)), func_021E0E40(1, *((int *) (record + 8))));
      }
      tmp = *((u32 *) record);
      digit = tmp - 1;
      func_0201F35C(text, digit, 1, 1, 1);
      STRBUF_Append(*((void **) (p + 0x33C)), text);
      *((int *) ((((u32) p) + (group * 4)) + 0x354)) *= 10;
      *((int *) ((((u32) p) + (group * 4)) + 0x354)) += digit;
      used++;
      if (((int) used) >= (*((int *) ((((u32) p) + (group * 4)) + 0x328))))
      {
        group++;
        used = 0;
      }
      product = (*acc) * 10;
      *acc = product + ((u32) digit);
      i++;
    }
    while (((int) i) < (*((int *) (p + 0x23C))));
  }
  STRBUF_Delete(text);
  func_021E1374(p, 3);
  *((int *) (p + 0x350)) = 2;
}







void func_021E1850(const Record_021E111C *records)
{
    char *p=(char *)records;
    int i,old,value,offset;
    ((struct CodeinWorkA *)p)->f1DC=1;
    p[0x1f4]=0;
    if (((struct CodeinWorkA *)p)->f240==0) {
        i=((struct CodeinWorkA *)p)->f23C-1;
        ((struct CodeinWorkA *)p)->f188=i;
        value=records[i].value;
        ((struct CodeinWorkA *)p)->f318=1;
        ((struct CodeinWorkA *)p)->f31C=value;
        ((struct CodeinWorkA *)p)->f320=1;
    } else {
        i=((struct CodeinWorkA *)p)->f188;
        CLACT_SetActorAnimSeq((struct Obj *)records[i].handle,func_021E0E40(((Record_021E111C *)records)[i].tag=0,records[i].mode));
        old=records[i].value;
        if (i>0) {
            CLACT_SetActorAnimSeq((struct Obj *)records[i-1].handle,func_021E0E40(records[i-1].tag,records[i-1].mode));
            value=records[i-1].value;
            if (old!=value) {
                ((struct CodeinWorkA *)p)->f318=1;
                ((struct CodeinWorkA *)p)->f31C=value;
                ((struct CodeinWorkA *)p)->f320=1;
            } else {
                ((struct CodeinWorkA *)p)->f318=2;
                ((struct CodeinWorkA *)p)->f31C=i-1;
            }
        } else ((struct CodeinWorkA *)p)->f350=1;
    }
}







void func_021E1910(char *p) {
    int i;
    Table_021E1910 table;
    for(i=0;i<12;i++)*(char **)(p+i*28+16)=(p+0x298)+i*4;
    table=d_021E3880;
    for(;i<24;i++){
        *(u8 *)(p+i*4+0x298)=table.row[i-12].b-table.row[i-12].d;
        *(u8 *)(p+i*4+0x29A)=table.row[i-12].a-table.row[i-12].c;
        *(u8 *)(p+i*4+0x299)=table.row[i-12].b+table.row[i-12].d;
        *(u8 *)(p+i*4+0x29B)=table.row[i-12].a+table.row[i-12].c;
    }
    ((struct CodeinWorkA *)p)->f2F8=255;
    ((struct CodeinWorkA *)p)->f294=BUTTON_MAN_Create((u8 *)(p+0x298),(int)func_021E19EC,(int)p,((struct CodeinWorkA *)p)->f34C);
}







/*
 * 2026-10-05 wave P5 lane T5 (pengy share): earlier DIFF, two residues (merged far-branch stubs, idx-12 CSE).
 * 2026-10-05 wave P5 lane T5b: EXACT with the ov129 021D958C forms: idx is u32 (unsigned % and / by plain 5),
 *   `if (*(int *)(p + 0x22C) != 1) return;` then `if (arg == 0) {`, non-const Record_021E111C pointer. One compile.
 *   Callbacks: func_021E1910 passes this as BUTTON_MAN_Create's callback (idx, arg, obj).
 */
void func_021E19EC(u32 idx, int arg, char *p)
{
    Record_021E111C *rec = (Record_021E111C *)p;
    u32 i, j, v;
    int old, val;
    if (*(int *)(p + 0x22C) != 1) return;
    if (arg == 0) {
    if (idx <= 11) {
        if (rec[idx].mode == 1) {
            *(int *)(p + 0x318) = 2;
            *(int *)(p + 0x31C) = idx;
        } else {
            *(int *)(p + 0x318) = 1;
            *(int *)(p + 0x31C) = rec[idx].value;
        }
        func_020061E4(0x703);
        return;
    }
    if (idx == 0x16) {
        u32 x, y;
        Point args;
        *(u16 *)(p + 0x1B8) = 0;
        *(u16 *)(p + 0x1BA) = 2;
        func_020061E4(0x703);
        func_02035D20(&x, &y);
        args.x = x;
        args.y = y;
        func_021FD860((void *)(*(int *)(p + 0x348)), 1, &args);
    } else if (idx == 0x17) {
        u32 x, y;
        Point args;
        *(u16 *)(p + 0x1B8) = 3;
        *(u16 *)(p + 0x1BA) = 2;
        func_020061E4(0x703);
        func_02035D20(&x, &y);
        args.x = x;
        args.y = y;
        func_021FD860((void *)(*(int *)(p + 0x348)), 1, &args);
    } else {
        *(u16 *)(p + 0x1B8) = (idx - 12) % 5;
        *(u16 *)(p + 0x1BA) = (idx - 12) / 5;
        func_020061E4(0x703);
    }
    if (idx >= 12 && idx <= 21) {
        u32 x, y;
        Point args;
        if (*(int *)(p + 0x240) != 0) {
        func_02035D20(&x, &y);
        args.x = x;
        args.y = y;
        func_021FD860((void *)(*(int *)(p + 0x348)), 1, &args);
        i = *(int *)(p + 0x188);
        v = idx - 11;
        CLACT_SetActorAnimSeq((struct Obj *)rec[i].handle, (u16)func_021E0E40(rec[i].tag = v, rec[i].mode));
        old = rec[i].value;
        j = i + 1;
        if (j == *(u32 *)(p + 0x23C)) {
            *(int *)(p + 0x318) = 1;
            *(int *)(p + 0x31C) = 0;
            *(int *)(p + 0x320) = 0;
        } else {
            val = rec[j].value;
            if (old != val) {
                *(int *)(p + 0x318) = 1;
                *(int *)(p + 0x31C) = val;
                *(int *)(p + 0x320) = 0;
            } else {
                *(int *)(p + 0x318) = 2;
                *(int *)(p + 0x31C) = j;
            }
        }
        }
    } else if (idx == 0x16) {
        func_021E1850((const Record_021E111C *)p);
    } else {
        func_021E1708(p);
    }
    }
}







/*
 * Extent remainder: zero alignment halfword at 021E1BFE.
 */
void func_021E1BA8(char *p)
{
    switch (((struct CodeinWorkA *)p)->f318) {
    case 0: break;
    case 1:
        func_021E11D0(p,((struct CodeinWorkA *)p)->f31C);
        func_021E0E4C(p);
        func_021E0E90(p,1);
        func_021E1374(p,2);
        ((struct CodeinWorkA *)p)->f318=255;
        break;
    case 2:
        func_021E0D00(p,((struct CodeinWorkA *)p)->f31C);
        func_021E1C00(p);
        break;
    case 255: break;
    }
}








void func_021E1C00(char *p)
{
    ((struct CodeinWorkA *)p)->f318 = 0;
    ((struct CodeinWorkA *)p)->f31C = 0;
    ((struct CodeinWorkA *)p)->f320 = 0;
}








/*
 * extent: final two bytes are alignment padding.
 */
int func_021E1C14(char *p,int a){int i,n; n=((struct CodeinWorkA *)p)->f23C;for(i=0;i<n;i++){if(a==*(int *)(p+i*28+4))return i;}return 0;}







/*
 * checks: 1 n/a no calls; 2 matched 1C14 confirms signed index/raw28 stride; 3 enum index DIFF7, unsigned-long count and long index each DIFF4; 4 count/address reuse DIFF4, permuter expands the read-only count field at guard and return; 5 refreshed directory and neighbours; no stack object.
 * matching: re-reading count at guard and return instead of a cached scalar lets the dying offset use r4. No stores or calls can change count during this function.
 * extent: 58 code bytes, alignment padding at021E1C7E..021E1C80; next function starts1C80.
 * retry: 5 one runs, once-only permuter budget300 found expand(n x2) after9 candidates; emitted DIFF4 baseline agrees; winner validated by run6.
 */
int func_021E1C44(const char *p, int a)
{
  int i;
  int found;
  unsigned n;
  n = *((const unsigned *) (p + 0x23c));
  found = 0;
  for (i = 0; i < ((int) (*((const unsigned *) (p + 0x23c)))); i++)
  {
    if (a == (*((const int *) ((p + (i * 28)) + 4))))
      found = 1;
    else
      if (found == 1)
      return i - 1;
  }

  return (*((const unsigned *) (p + 0x23c))) - 1;
}






int func_021E1C80(struct Obj0203159C *obj,int unused,char *arg)
{
    struct CodeinWorkF *p;
    int i;
    Point pair;
    p=PROCSYS_AllocProcWork(obj,32,func_021F9B9C((struct Obj24810 *)(((struct CodeinArgC *)arg)->fC)));
    func_02082BCC(p,0,32);
    p->f18=arg;
    p->f8=func_021F9B9C((struct Obj24810 *)(((struct CodeinArgC *)arg)->fC));
    p->f4=(int)func_021FD6D8((int)p,(int)func_021E1DA8,p->f8);
    p->f0=func_0201C440((void *)(p->f8));
    p->fC=(int)func_021FD12C(((struct CodeinArgC *)arg)->f8,(void *)(p->f0),p->f8);
    func_021FD170((char *)(p->fC),(char *)(((struct CodeinArgC *)arg)->f8),(void *)111);
    for (i=0;i<2;i++) *(int *)((char *)p+i*4+0x10)=(int)func_021FD760(((struct CodeinArgC *)arg)->f4,(char *)(((struct CodeinArgC *)arg)->f8),i,p->f8);
    pair=d_021E38E0;
    func_021FD860((void *)(p->f10), 4, &pair);
    return 1;
}






int func_021E1D10(struct S020315D4 *a,int b,struct CodeinArgA *q,struct CodeinWorkA *p){int i;for(i=0;i<2;i++)func_021FD820(*(char **)((char *)p+i*4+16));func_021FD15C(p->fC,q->f8);func_0201C4C0(p->f0);func_021FD714((void *)((*(int *)&p->f4)));func_020315D4(a);return 1;}






int func_021E1D48(int a,int b,int c,struct CodeinWorkB *p)
{
    int i;
    if (!GAME_DATA_IsSaving((const u8 *)(((struct CodeinSubA *)(*(char * *)&p->f18))->f14)) && func_021FF88C((char *)(((struct CodeinSubA *)(*(char * *)&p->f18))->f10))==2) {
        func_021F9C6C((void *)((*(int *)&((struct CodeinSubA *)(*(char * *)&p->f18))->fC)));
        return 1;
    }
    func_021FD71C((u8 *)(p->f4));
    if (func_021FD72C((int *)(p->f4))) return 1;
    for (i=0;i<2;i++) func_021FD854((char *)(*(int *)((char *)p+i*4+0x10)));
    PRINTSYS_QUE_Main((struct PrintSys *)(p->f0));
    func_021FD1BC((void *)(p->fC));
    return 0;
}





void func_021E1DA8(int a,int *state,struct CodeinWorkB *p)
{
    switch (*state) {
    case 0: func_021FE784(**(int * *)&p->f18,2,3,0); *state=1; break;
    case 1: if (func_021FE7B0((int *)(**(int * *)&p->f18))) *state=2; break;
    case 2: func_021FD73C((int *)a,(int)func_021E1E3C); break;
    }
}





void func_021E1DF0(int *a,int *state,struct CodeinWorkB *p)
{
    switch (*state) {
    case 0: func_021FE784(**(int * *)&p->f18,2,3,1); *state=1; break;
    case 1: if (func_021FE7B0((int *)(**(int * *)&p->f18))) *state=2; break;
    case 2: func_021F9BA0((unsigned int *)((*(int *)&((struct CodeinSubA *)(*(char * *)&p->f18))->fC))); func_021FD744(a); break;
    }
}





/*
 * lever: keep the copied u64 and quotient distinct; use the emitted _ull_mod runtime symbol.
 */
void func_021E1E3C(int *task,int *state,struct CodeinWorkB *p) {
    u32 out;
    u64 total;
    u32 msg,x,y; Point pair;
    void *str,*expanded,*ws,*bank;
    u64 copy,quotient;
    int result;
    switch(*state) {
    case 0:
        BATTLE_REC_Load(GAME_DATA_GetSaveControl((*(void * *)&((struct CodeinSubA *)(*(char * *)&p->f18))->f14)),89,&out,0);
        if(out==1)*state=1;else func_021FD73C((int *)task,(int)func_021E1DF0);break;
    case 1:
        p->f1C=0;func_021FF54C((*(void * *)&((struct CodeinSubA *)(*(char * *)&p->f18))->f10),2,0);*state=2;break;
    case 2:
        ++p->f1C;
        if(func_021FF648((*(void * *)&((struct CodeinSubA *)(*(char * *)&p->f18))->f10))) {
            total=0;
            if(p->f1C>=96) {
                result=func_021FF72C((*(void * *)&((struct CodeinSubA *)(*(char * *)&p->f18))->f10),(int *)(&msg));
                if(result==0) {
                    if(func_021FF67C((*(void * *)&((struct CodeinSubA *)(*(char * *)&p->f18))->f10),&total)) {
                        bank=(void *)func_021FC214(*(char * *)&((struct CodeinSubA *)(*(char * *)&p->f18))->f8);
                        ws=(void *)func_021FC21C(*(char * *)&((struct CodeinSubA *)(*(char * *)&p->f18))->f8);
                        str=func_02045EC0(bank,334);expanded=STRBUF_Create(128,0x8059);
                        copy=total;quotient=copy/100000;
                        func_0201EFA4(ws,2,(u32)(copy%100000),5,2,1);
                        func_0201EFA4(ws,1,(u32)(quotient%100000),5,2,1);
                        func_0201EFA4(ws,0,(u32)(quotient/100000),2,2,1);
                        func_0201F250(ws,expanded,str);
                        func_021FD19C((char *)(p->fC),(void *)((*(int *)&((struct CodeinSubA *)(*(char * *)&p->f18))->f8)),expanded);
                        STRBUF_Delete(expanded);STRBUF_Delete(str);
                    }
                } else if(result==3) {
                    func_021F9C6C((void *)((*(void * *)&((struct CodeinSubA *)(*(char * *)&p->f18))->fC)));func_021FD744(task);break;
                } else func_021FD170((char *)(p->fC),(char *)((*(int *)&((struct CodeinSubA *)(*(char * *)&p->f18))->f8)),(void *)msg);
                func_021FD860((void *)(p->f10), 0, 0);*state=4;
            }
        }break;
    case 3:func_021FD73C((int *)task,(int)func_021E1DF0);break;
    case 4:
        if(TOUCHPANEL_GetTrg()) {
            func_02035D20(&x,&y);pair.x=x;pair.y=y;func_021FD860((void *)((*(int *)&p->f14)), 1, &pair);
            func_020061E4(0x703);*state=3;
        }break;
    }
}




int func_021E2028(struct Obj0203159C *obj,int unused,char *arg)
{
    char *p;
    int i;
    if (((struct CodeinArgC *)arg)->f0>=4) func_02034714(d_021E39B4,0,d_021E39B4);
    p=PROCSYS_AllocProcWork(obj,40,func_021F9B9C((struct Obj24810 *)(((struct CodeinArgC *)arg)->f10)));
    func_02082BCC(p,0,40);
    ((struct CodeinWorkC *)p)->f20=arg;
    ((struct CodeinWorkC *)p)->f1C=func_021F9B9C((struct Obj24810 *)(((struct CodeinArgC *)arg)->f10));
    ((struct CodeinWorkC *)p)->f8=(int)func_021FD6D8((int)p,(int)func_021E214C,((struct CodeinWorkC *)p)->f1C);
    ((struct CodeinWorkC *)p)->f0=func_0201C440((void *)(((struct CodeinWorkC *)p)->f1C));
    func_021E23C8(p,(const Input *)arg);
    for (i=0;i<2;i++) *(int *)(p+i*4+0x14)=(int)func_021FD760(((struct CodeinArgC *)arg)->f8,(char *)(((struct CodeinArgC *)arg)->fC),i,((struct CodeinWorkC *)p)->f1C);
    return 1;
}




/*
 * Extent remainder: zero alignment halfword at 021E20F6.
 */
int func_021E20A4(int obj,int b,char *arg,char *p)
{
    int i;
    for (i=0;i<2;i++) func_021FD820((char *)(*(int *)(p+i*4+0x14)));
    if ((*(int *)&((struct CodeinSubA *)(((struct CodeinWorkA *)p)->f20))->f1C)) func_021E24AC(p,arg);
    else { func_021E24AC(p,arg); func_021E24C4(p,arg); }
    func_0201C4C0((struct PrintSys *)((*(int *)&((struct CodeinWorkA *)p)->f0)));
    func_021FD714((void *)((*(int *)&((struct CodeinWorkA *)p)->f8)));
    func_020315D4((struct S020315D4 *)obj);
    return 1;
}




int func_021E20F8(int a,int b,int c,struct CodeinWorkA *p)
{
    int i;
    func_021FD71C((u8 *)((*(int *)&p->f8)));
    if (func_021FD72C((int *)((*(int *)&p->f8)))) return 1;
    for (i=0;i<2;i++) func_021FD854((char *)(*(int *)((char *)p+i*4+0x14)));
    PRINTSYS_QUE_Main((struct PrintSys *)((*(int *)&p->f0)));
    if ((*(int *)&p->f4)) func_021FD1BC((void *)((*(int *)&p->f4)));
    for (i=0;i<2;i++) if (*(int *)((char *)p+i*4+0xc)) func_021FC830((u8 *)(*(int *)((char *)p+i*4+0xc)));
    return 0;
}




void func_021E214C(int *task,int *state,struct CodeinWorkA *p)
{
    switch (*state) {
    case 0: func_021FE784(((struct CodeinSubA *)(p->f20))->f4,2,3,0); *state=1; break;
    case 1: if (func_021FE7B0(*(int * *)&((struct CodeinSubA *)(p->f20))->f4)) *state=2; break;
    case 2: func_021FD73C(task,(int)func_021E21E0); break;
    }
}




void func_021E2194(int *task,int *state,struct CodeinWorkA *p)
{
    switch (*state) {
    case 0: func_021FE784(((struct CodeinSubA *)(p->f20))->f4,2,3,1); *state=1; break;
    case 1: if (func_021FE7B0(*(int * *)&((struct CodeinSubA *)(p->f20))->f4)) *state=2; break;
    case 2: func_021F9BA0((unsigned int *)(((struct CodeinSubA *)(p->f20))->f10)); func_021FD744(task); break;
    }
}




/*
 * lever: separate function-scope coordinate pairs retain the switch cases' stack slots.
 */
void func_021E21E0(int task,int *state,char *p) {
    u32 x0,y0,x1,y1; Point first; u32 x9,y9; Point second;
    u32 old; int result;
    switch(*state) {
    case 0:
        if(func_02035D20(&x0,&y0)) {
            if(func_021E24F8(p,x0,y0)) {func_021FD170((char *)((*(int *)&((struct CodeinWorkC *)p)->f4)),(char *)((*(int *)&((struct CodeinSubA *)(((struct CodeinWorkC *)p)->f20))->fC)),(void *)322);*state=1;}
            else if(func_021E2538(p,x0,y0))*state=10;
        } break;
    case 1:
        if(func_02035D20(&x1,&y1)) {
            if(func_021E24F8(p,x1,y1))*state=2;
            else if(func_021E2538(p,x1,y1))*state=10;
        } break;
    case 2:func_021FE784(((struct CodeinSubA *)(((struct CodeinWorkC *)p)->f20))->f4,2,2,1);++*state;break;
    case 3:
        if(func_021FE7B0(*(int * *)&((struct CodeinSubA *)(((struct CodeinWorkC *)p)->f20))->f4)) {
            func_021E24C4(p,((struct CodeinWorkC *)p)->f20);
            func_021FD170((char *)((*(int *)&((struct CodeinWorkC *)p)->f4)),(char *)((*(int *)&((struct CodeinSubA *)(((struct CodeinWorkC *)p)->f20))->fC)),(void *)323);
            first.x=128;first.y=96;func_021FD860((void *)(((struct CodeinWorkC *)p)->f14), 4,&first);
            ((struct CodeinWorkC *)p)->f24=0;++*state;
        } break;
    case 4:func_021FE784(((struct CodeinSubA *)(((struct CodeinWorkC *)p)->f20))->f4,2,2,0);++*state;break;
    case 5:if(func_021FE7B0(*(int * *)&((struct CodeinSubA *)(((struct CodeinWorkC *)p)->f20))->f4))++*state;break;
    case 6:
        func_021D76A8(((struct CodeinSubA *)(((struct CodeinWorkC *)p)->f20))->f14,((struct CodeinWorkC *)p)->f1C,**(int * *)&((struct CodeinWorkC *)p)->f20);
        ++((struct CodeinWorkC *)p)->f24;++*state;break;
    case 7:
        result=func_021D76D8((char *)(((struct CodeinSubA *)(((struct CodeinWorkC *)p)->f20))->f14),**(int * *)&((struct CodeinWorkC *)p)->f20);
        ++((struct CodeinWorkC *)p)->f24;
        if((u32)(result-2)<=1) {(*(int *)&((struct CodeinSubA *)(((struct CodeinWorkC *)p)->f20))->f1C)=1;*state=8;}break;
    case 8:
        old=((struct CodeinWorkC *)p)->f24;((struct CodeinWorkC *)p)->f24=old+1;
        if(old>96) {func_021FD860((void *)(((struct CodeinWorkC *)p)->f14), 0,0);func_021FD170((char *)((*(int *)&((struct CodeinWorkC *)p)->f4)),(char *)((*(int *)&((struct CodeinSubA *)(((struct CodeinWorkC *)p)->f20))->fC)),(void *)324);*state=9;}break;
    case 9:
        if(TOUCHPANEL_GetTrg()) {
            func_02035D20(&x9,&y9);second.x=x9;second.y=y9;
            func_021FD860((void *)(((struct CodeinWorkC *)p)->f18), 1,&second);func_020061E4(0x703);*state=10;
        }break;
    case 10:func_021FD73C((int *)task,(int)func_021E2194);break;
    }
}




/*
 * lever: bounded permuter extracted index/base/heap-address temporaries;
 *   unsigned index arithmetic and top-of-block declarations preserve behavior.
 *   This removes the 12-byte setup scheduling residue; fixed one confirms EXACT.
 * arity: 0201EE0C's unit declares five arguments; this caller visibly supplies
 *   the sixth stack word (2), retained without editing the callee.
 */
void func_021E23C8(char *p,const Input *q) {
    struct WordSet *ws;
    struct U16Vec *str,*expanded;
    int font,bank,i;
    const Rec *r;
    char *slot;
    u32 tmp1,tmp;
    u16 *tmp2;
    if(!((struct CodeinWorkC *)p)->f4) ((struct CodeinWorkC *)p)->f4=func_021FD12C((int)q->owner,(void *)(((struct CodeinWorkC *)p)->f0),((struct CodeinWorkC *)p)->f1C);
    ws=(struct WordSet *)func_021FC21C(q->owner);
    str=func_02045EC0((struct MsgBank *)func_021FC214(q->owner),321);
    tmp2=(u16 *)(p+28);
    expanded=STRBUF_Create(128,*tmp2);
    tmp1=q->base;
    tmp=q->index;
    func_0201EE0C(ws,0,*(void **)(q->base+tmp*4+16),
        *(u32 *)(tmp1+tmp*4+32),1,2);
    func_0201F250(ws,expanded,str);
    func_021FD19C(((struct CodeinWorkC *)p)->f4,q->owner,expanded);
    STRBUF_Delete(expanded); STRBUF_Delete(str);
    func_021FB964((void *)((int)q->owner),30,((struct CodeinWorkC *)p)->f1C);
    font=func_021FC20C(q->owner);
    bank=func_021FC214(q->owner);
    for(i=0;i<2;i++) {
        r=&d_021E3900[i]; slot=p; slot=slot+i*4;
        ((struct CodeinWorkC *)slot)->fC=func_021FC6A4(4,r->a,r->b,r->c,r->d,14,(*(void * *)&((struct CodeinWorkC *)p)->f0),((struct CodeinWorkC *)p)->f1C);
        func_021FC754(*(char * *)&((struct CodeinWorkC *)slot)->fC,(void *)bank,r->value,(void *)font,0x3da0);
    }
}





void func_021E24AC(char *p, char *a1)
{
    if ((*(int *)&((struct CodeinWorkA *)p)->f4) != 0) {
        func_021FD15C((void *)((*(int *)&((struct CodeinWorkA *)p)->f4)), ((struct CodeinA1A *)a1)->fC);
        (*(int *)&((struct CodeinWorkA *)p)->f4) = 0;
    }
}








/*
 * extent: final two bytes are alignment padding.
 */
void func_021E24C4(char *p,char *q){int i;for(i=0;i<2;i++){if(*(void **)(p+i*4+12)){func_021FC734(*(void **)(p+i*4+12));*(void **)(p+i*4+12)=0;}}func_020409B4(4);func_021FBDA4((*(int *)&((struct CodeinArgA *)q)->fC),30);}









int func_021E24F8(char *p, int a, int b)
{
    int ok = ((unsigned int)(a - 0x20) <= 0x48) &
             ((unsigned int)(b - 0x30) <= 0x10);
    if (ok) {
        Point args;
        args.x = a;
        args.y = b;
        func_021FD860((void *)(((struct CodeinWorkC *)p)->f18), 1, &args);
        func_020061E4(0x703);
    }
    return ok;
}









int func_021E2538(char *p, int a, int b)
{
    int ok = ((unsigned int)(a - 0x90) <= 0x48) &
             ((unsigned int)(b - 0x30) <= 0x10);
    if (ok) {
        Point args;
        args.x = a;
        args.y = b;
        func_021FD860((void *)(((struct CodeinWorkC *)p)->f18), 1, &args);
        func_020061E4(0x703);
    }
    return ok;
}








int func_021E2578(void *obj,int b,char *q)
{
    struct CodeinWorkD *p;
    int i;
    p=PROCSYS_AllocProcWork(obj,0x54,func_021F9B9C((*(void * *)&((struct CodeinArgA *)q)->f10)));
    func_02082BCC(p,0,0x54);
    p->f3C=q;
    p->f38=func_021F9B9C((*(void * *)&((struct CodeinArgA *)q)->f10));
    p->f0=BMP_OAM_CreateSys(p->f38,(*(void * *)&((struct CodeinArgA *)q)->f4));
    p->fC=func_021FD6D8((int)p,(int)func_021E26B8,p->f38);
    (*(unsigned int *)&p->f4)=func_0201C440((void *)(unsigned int)p->f38);
    for (i=0;i<2;i++) *(void **)((char *)p+i*4+0x30)=func_021FD760((unsigned int)((*(void * *)&((struct CodeinArgA *)q)->f4)),(char *)(((struct CodeinArgA *)q)->f8),i,p->f38);
    return 1;
}








/*
 * Extent remainder: zero alignment halfword at 021E263E.
 */
int func_021E25E4(int obj,int b,int c,char *p)
{
    int i;
    func_021E2E48(p+0x4c,(int)p,(int)(((struct CodeinWorkA *)p)->f3C));
    for (i=0;i<2;i++) func_021FD820(*(char **)(p+i*4+0x30));
    if (((struct CodeinWorkA *)p)->f8) {
        func_021FD15C(((struct CodeinWorkA *)p)->f8,(*(int *)&((struct CodeinSubA *)(((struct CodeinWorkA *)p)->f3C))->f8));
        *(int *)&((struct CodeinWorkA *)p)->f8=0;
    }
    func_0201C4C0((struct PrintSys *)((*(int *)&((struct CodeinWorkA *)p)->f4)));
    func_021FD714((void *)((*(int *)&((struct CodeinWorkA *)p)->fC)));
    BMP_OAM_DeleteSys((void *)((*(int *)&((struct CodeinWorkA *)p)->f0)));
    func_021F9BA0((unsigned int *)(((struct CodeinSubA *)(((struct CodeinWorkA *)p)->f3C))->f10));
    func_020315D4((struct S020315D4 *)obj);
    return 1;
}








int func_021E2640(int a,int b,int c,struct CodeinWorkA *p)
{
    int i;
    if (!GAME_DATA_IsSaving((const u8 *)(((struct CodeinSubA *)(p->f3C))->f14)) && func_021FF88C((char *)((*(int *)&((struct CodeinSubA *)(p->f3C))->fC)))==2) {
        func_021F9C6C((void *)(((struct CodeinSubA *)(p->f3C))->f10));
        return 1;
    }
    func_021FD71C((u8 *)((*(int *)&p->fC)));
    if (func_021FD72C((int *)((*(int *)&p->fC)))) return 1;
    for (i=0;i<2;i++) func_021FD854((char *)(*(int *)((char *)p+i*4+0x30)));
    PRINTSYS_QUE_Main((struct PrintSys *)((*(int *)&p->f4)));
    if ((*(int *)&p->f8)) func_021FD1BC((void *)((*(int *)&p->f8)));
    for (i=0;i<2;i++) if (*(int *)((char *)p+i*4+0x28)) func_021FC830((u8 *)(*(int *)((char *)p+i*4+0x28)));
    return 0;
}






void func_021E26B8(int *task,State_021E21E0 *state,char *p) {
    u32 req[2];
    u32 msg;
    int extra;char *rec;
    u32 x,y;Point click;SOCLResource cb;
    int result,found,i;
    u64 value;char *arg;
    switch(*state) {
    case 0:
        func_021E2F98(&cb);arg=*(char **)(p+0x3c);*(SOCLResource *)(p+0x4c)=cb;
        func_021E2E30((char *)p+0x4c,(int)p,(int)arg);*state=1;break;
    case 1:func_021FE784(**(int **)(p+0x3c),2,3,0);*state=2;break;
    case 2:if(func_021FE7B0((int *)**(int **)(p+0x3c)))*state=3;break;
    case 3:
        func_02082BCC(req,0,8);*(u64 *)req=*(u64 *)(*(char **)(p+0x3c)+0x1c);
        func_021FF54C(*(void **)(*(char **)(p+0x3c)+12),3,(const int *)req);
        *(u32 *)(p+0x44)=0;*state=4;break;
    case 4:
        ++*(u32 *)(p+0x44);
        if(func_021FF648(*(void **)(*(char **)(p+0x3c)+12)) && *(u32 *)(p+0x44)>96) {
            func_021FD860((void *)(*(int *)(p+0x30)), 0, 0);*state=5;
        }break;
    case 5:
        result=func_021FF72C(*(void **)(*(char **)(p+0x3c)+12),(int *)(&msg));
        if(result==0) {
            if(func_021FF698(*(void **)(*(char **)(p+0x3c)+12),(int)(&rec),&extra)) {
                BATTLE_REC_SetData(rec,rec+0x80,rec+0xc4,(unsigned int)GAME_DATA_GetSaveControl(*(void **)(*(char **)(p+0x3c)+0x14)));
                found=0;value=BATTLE_REC_GetHeaderParam((u8 *)BATTLE_REC_GetHeader(),4,0);
                i=1;arg=*(char **)(p+0x3c);
                for(;i<=3;i++) {
                    if(*(u64 *)(*(char **)(arg+0x18)+i*8+0x30)==value) {found=1;break;}
                }
                if(found==1) {func_021FD170((char *)(*(int *)(p+8)),(char *)(*(int *)(arg+8)),(void *)316);*state=9;}
                else *state=6;
            } else {func_021FD170((char *)(*(int *)(p+8)),(char *)(*(int *)(*(char **)(p+0x3c)+8)),(void *)339);*state=9;}
        } else {func_021FD170((char *)(*(int *)(p+8)),(char *)(*(int *)(*(char **)(p+0x3c)+8)),(void *)msg);*state=9;}
        break;
    case 9:
        if(TOUCHPANEL_GetTrg()) {
            func_02035D20(&x,&y);click.x=x;click.y=y;func_021FD860((void *)(*(int *)(p+0x34)), 1, &click);
            func_020061E4(0x703);*state=10;
        }break;
    case 6:func_021FE784(**(int **)(p+0x3c),2,3,1);*state=7;break;
    case 7:if(func_021FE7B0((int *)**(int **)(p+0x3c)))*state=8;break;
    case 8:func_021E2E48((char *)p+0x4c,(int)((char *)p),(int)(*(char **)(p+0x3c)));func_021FD73C((int *)task,(int)func_021E2910);break;
    case 10:func_021FE784(**(int **)(p+0x3c),2,3,1);*state=11;break;
    case 11:if(func_021FE7B0((int *)**(int **)(p+0x3c)))*state=12;break;
    case 12:func_021E2E48((char *)p+0x4c,(int)((char *)p),(int)(*(char **)(p+0x3c)));func_021FD744(task);break;
    }
}






/*
 * lever: function-scope pair locals preserve stack-slot order across switch cases.
 */
void func_021E2910(int *task,int *state,char *p) {
    u32 x,y;
    Point first,second,cb;
    int i;
    switch(*state) {
    case 0: {
        func_021E300C(&cb);
        *(Point *)(p+0x4c)=cb;
        func_021E2E30(p+0x4c,(int)p,*(int *)&((struct CodeinWorkA *)p)->f3C);
        *state=1; break;
    }
    case 1: func_021FE784(**(int * *)&((struct CodeinWorkA *)p)->f3C,2,3,0); *state=2; break;
    case 2: if(func_021FE7B0((int *)**(int * *)&((struct CodeinWorkA *)p)->f3C)) *state=3; break;
    case 3: {
        if(func_02035D20(&x,&y)) {
            for(i=0;i<=2;i++) {
                if(func_021FB4B4((unsigned int *)(*(int *)(p+i*4+0x14)),x,y)) {
                    first.x=x; first.y=y;
                    func_021FD860((void *)((*(int *)&((struct CodeinWorkA *)p)->f34)), 1, &first);
                    (*(int *)&((struct CodeinWorkA *)p)->f10)=i;
                    if(*(int *)((u32)*(char * *)&((struct CodeinSubA *)(((struct CodeinWorkA *)p)->f3C))->f18+(u32)i*4+4)) *state=7;
                    else *state=4;
                }
            }
            if(func_021FB4B4((unsigned int *)((*(int *)&((struct CodeinWorkA *)p)->f20)),x,y)) {
                second.x=x; second.y=y;
                func_021FD860((void *)((*(int *)&((struct CodeinWorkA *)p)->f34)), 1, &second); *state=10;
            }
        }
        break;
    }
    case 4: func_021FE784(**(int * *)&((struct CodeinWorkA *)p)->f3C,2,3,1); *state=5; break;
    case 5: if(func_021FE7B0((int *)**(int * *)&((struct CodeinWorkA *)p)->f3C)) *state=6; break;
    case 6: func_021E2E48(p+0x4c,(int)p,(int)(((struct CodeinWorkA *)p)->f3C)); func_021FD73C(*(int * *)&((struct CodeinWorkA *)p)->fC,(int)func_021E2C2C); break;
    case 7: func_021FE784(**(int * *)&((struct CodeinWorkA *)p)->f3C,2,3,1); ++*state; break;
    case 8: if(func_021FE7B0((int *)**(int * *)&((struct CodeinWorkA *)p)->f3C)) ++*state; break;
    case 9: func_021E2E48(p+0x4c,(int)p,(int)(((struct CodeinWorkA *)p)->f3C)); func_021FD73C(*(int * *)&((struct CodeinWorkA *)p)->fC,(int)func_021E2AE0); break;
    case 10: func_021FE784(**(int * *)&((struct CodeinWorkA *)p)->f3C,2,3,1); *state=11; break;
    case 11: if(func_021FE7B0((int *)**(int * *)&((struct CodeinWorkA *)p)->f3C)) *state=12; break;
    case 12: func_021E2E48(p+0x4c,(int)p,(int)(((struct CodeinWorkA *)p)->f3C)); func_021FD744(task); break;
    }
}






/*
 * lever: Declare scalar locals before Point; assign the returned Point as a whole to p+0x4C. Separate word stores produced the wrong stack/copy schedule.
 */
void func_021E2AE0(int *task,unsigned *state,char *p)
{
    unsigned x,y;
    SOCLResource a;
    switch(*state) {
    case 0:
        func_021E2E60(&a);
        *(SOCLResource *)(p+0x4c)=a;
        func_021E2E30(p+0x4c,(int)p,*(int *)&((struct CodeinWorkA *)p)->f3C);
        ++*state; break;
    case 1:
        func_021FE784(**(int * *)&((struct CodeinWorkA *)p)->f3C,2,3,0);
        ++*state; break;
    case 2:
        if(func_021FE7B0(**(int ** *)&((struct CodeinWorkA *)p)->f3C)) ++*state;
        break;
    case 3:
        if(func_02035D20(&x,&y)) {
            if(func_021E31E8(p,x,y)) *state=4;
            if(func_021E3228(p,x,y)) *state=7;
        }
        break;
    case 4:
        func_021FE784(**(int * *)&((struct CodeinWorkA *)p)->f3C,2,3,1);
        ++*state; break;
    case 5:
        if(func_021FE7B0(**(int ** *)&((struct CodeinWorkA *)p)->f3C)) ++*state;
        break;
    case 6:
        func_021E2E48(p+0x4c,(int)p,(int)(((struct CodeinWorkA *)p)->f3C));
        func_021FD73C(task,(int)func_021E2C2C); break;
    case 7:
        func_021FE784(**(int * *)&((struct CodeinWorkA *)p)->f3C,2,3,1);
        ++*state; break;
    case 8:
        if(func_021FE7B0(**(int ** *)&((struct CodeinWorkA *)p)->f3C)) ++*state;
        break;
    case 9:
        func_021E2E48(p+0x4c,(int)p,(int)(((struct CodeinWorkA *)p)->f3C));
        func_021FD73C(task,(int)func_021E2910); break;
    }
}





/*
 * 2026-10-05 (D8 lane19): re-verified, status unchanged; sole blocker is arm9 callee 0x0200B98C (no witness outside the caller). Needs a label seed. Source is byte-correct; no C change possible.
 * lever: Write the zero halfwords in source order p+0x40 then p+0x42; the reversed spelling exchanged those two store addresses.
 * blocker-symbols: BattleRecModeTable 0x0209DDCC data a4
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned long long u64;
 * extern const u16 BattleRecModeTable[];
 * u64 BATTLE_REC_GetHeaderParam(char *p,int selector,int index) {
 *     int i;
 *     u16 v;
 *     switch(selector) {
 *     case 0: v=((u16 *)p)[index];if(v>0x289)return 0;return v;
 *     case 1: return *(u8 *)(p+index+0x18)&0x7f;
 *     case 2: v=*(u16 *)(p+0x24);if(v>0x270f)return 0x270f;return v;
 *     case 3: for(i=0;i<0x29;i++)if(*(u16 *)(p+0x26)==BattleRecModeTable[i])return i;return 0;
 *     case 4: return *(u64 *)(p+0x38);
 *     case 5: return *(u8 *)(p+0x2a);
 *     case 6: return (*(u8 *)(p+index+0x18)&0x80)>>7;
 *     case 7: return *(u8 *)(p+0x2b);
 *     default:return 0;
 *     }
 * }
 */
void func_021E2C2C(int *task,unsigned *state,char *p)
{
    Point initial;
    Config_021E111C cfg;
    int x,y;
    Point pair;
    int r;
    switch(*state) {
    case 0:
        if(!*(void **)(p+8)) *(void **)(p+8)=func_021FD12C(*(int *)(*(char **)(p+0x3c)+8),(void *)(*(int *)(p+4)),*(u16 *)(p+0x38));
        func_021FD170(*(void **)(p+8),(char *)(*(int *)(*(char **)(p+0x3c)+8)),(void *)0x13d);
        initial.x=0x80;initial.y=0x60;
        func_021FD860((void *)(*(int *)(p+0x30)), 4, &initial);
        func_021FE784(**(int **)(p+0x3c),2,3,0);++*state;break;
    case 1:if(func_021FE7B0(**(int ***)(p+0x3c))) ++*state;break;
    case 2:
        *(int *)(p+0x44)=0;
        *(u16 *)(p+0x40)=0;*(u16 *)(p+0x42)=0;
        ++*state;break;
    case 3:
        r=func_021D7540((void *)(*(int *)(*(char **)(p+0x3c)+0x14)),*(int *)(p+0x10)+1,(unsigned char)(*(int *)(*(char **)(p+0x3c)+0x24)),(u16 *)(p+0x40),(u16 *)(p+0x42),*(u16 *)(p+0x38));
        if((unsigned)(r-2)<=1) {
            *(int *)(*(char **)(p+0x3c)+0x28)=1;
            *(int *)(*(char **)(p+0x3c)+0x2c)=*(int *)(p+0x10)+1;
            ++*state;
        }
        ++*(int *)(p+0x44);break;
    case 4:
        func_02082BCC(&cfg,0,8);
        cfg.wide=BATTLE_REC_GetHeaderParam((u8 *)BATTLE_REC_GetHeader(),4,0);
        func_021FF54C(*(char **)(*(char **)(p+0x3c)+12),8,(const int *)(&cfg));
        func_021FD170(*(void **)(p+8),(char *)(*(int *)(*(char **)(p+0x3c)+8)),(void *)0x13f);
        *(int *)(p+0x48)=0;++*(int *)(p+0x44);++*state;break;
    case 5:
        ++*(unsigned *)(p+0x44);++*(unsigned *)(p+0x48);
        if(func_021FF648(*(char **)(*(char **)(p+0x3c)+12)) && *(unsigned *)(p+0x44)>0x60 && *(unsigned *)(p+0x48)>0x3c) {
            func_021FD860((void *)(*(int *)(p+0x30)), 0, 0);
            func_021FD170(*(void **)(p+8),(char *)(*(int *)(*(char **)(p+0x3c)+8)),(void *)0x140);
            ++*state;
        }break;
    case 6:
        if(TOUCHPANEL_GetTrg()) {
            func_02035D20((u32 *)(&x),(u32 *)(&y));pair.x=x;pair.y=y;
            func_021FD860((void *)(*(int *)(p+0x34)), 1, &pair);
            func_020061E4((int)0x703);++*state;
        }break;
    case 7:func_021FE784(**(int **)(p+0x3c),2,3,1);++*state;break;
    case 8:if(func_021FE7B0(**(int ***)(p+0x3c))) ++*state;break;
    case 9:
        if(*(void **)(p+8)) {func_021FD15C(*(void **)(p+8),*(int *)(*(char **)(p+0x3c)+8));*(int *)(p+8)=0;}
        func_021FD744(task);break;
    }
}






void func_021E2E30(char *p, int a1, int a2)
{
    if (((struct CodeinWorkA *)p)->f0 != 0) {
        ((void (*)(int, int)) * (void **)p)(a1, a2);
        *(int *)&((struct CodeinWorkA *)p)->f0 = 0;
    }
}






void func_021E2E48(char *p,int a,int b) { void (*f)(int,int);f=*(void (**)(int,int))(p+4);if(f){f(a,b);*(int *)&((struct CodeinWorkA *)p)->f4=0;} }





void func_021E2E60(SOCLResource *p)
{
    *p=d_021E3910.pair;
}





/*
 * lever: Bounded permuter split the scaled index and delayed the base load, then introduced store-address temporaries after the constructor. Fixed one validated its behavior-preserving winning C.
 */
void func_021E2E70(char *p, const char *q)
{
  void *a;
  void *s;
  void *b;
  int h;
  int c;
  int i;
  const unsigned char *r;
  unsigned base;
  unsigned index;
  void **tmp;
  void **tmp1;
  char *tmp2;
  if (!(*((void **) (p + 8))))
    *((void **) (p + 8)) = func_021FD12C(*((int *) (q + 8)), (void *)(*((int *) (p + 4))), *((u16 *) (p + 0x38)));
  a = (void *) func_021FC21C(*((char **) (q + 8)));
  s = func_02045EC0((struct MsgBank *)func_021FC214(*((char **) (q + 8))), 0x141);
  b = STRBUF_Create(0x80, *((u16 *) (p + 0x38)));
  index = *((unsigned *) (p + 0x10));
  index = index * 4;
  base = *((unsigned *) (q + 0x18));
  func_0201EE0C(a, 0, (const void *)(*((unsigned *) ((base + index) + 0x14))), *((unsigned *) ((((unsigned) base) + index) + 0x24)), 1, 2);
  func_0201F250(a, b, s);
  func_021FD19C(*((void **) (p + 8)), (void *)(*((int *) (q + 8))), b);
  STRBUF_Delete(b);
  STRBUF_Delete(s);
  func_021FB964((void *)(*((int *) (q + 8))), 0x1e, *((u16 *) (p + 0x38)));
  h = func_021FC20C(*((char **) (q + 8)));
  c = func_021FC214(*((char **) (q + 8)));
  for (i = 0; i < 2; i++)
  {
    r = d_021E3928;
    r = r + (i * 8);
    tmp2 = p + 4;
    *((void **) ((p + (i * 4)) + 0x28)) = func_021FC6A4(4, r[0], r[1], r[2], r[3], 14, *((void **) tmp2), *((u16 *) (p + 0x38)));
    tmp1 = (void **) (0x28 + (p + (i * 4)));
    tmp = tmp1;
    func_021FC754(*tmp, (void *)c, (void *)(*((int *) (r + 4))), (void *)h, 0x3da0);
  }

}





void func_021E2F54(struct CodeinWorkA *p,struct CodeinArgA *q)
{
    int i;
    for (i=0;i<2;i++) {
        if (*(void **)((char *)p+i*4+0x28)) {
            func_021FC734(*(void **)((char *)p+i*4+0x28));
            *(int *)((char *)p+i*4+0x28)=0;
        }
    }
    func_020409B4(4);
    func_021FBDA4(q->f8,0x1e);
    if (p->f8) {
        func_021FD15C(p->f8,q->f8);
        *(int *)&p->f8=0;
    }
}
