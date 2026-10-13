/*
 * file:     fldmmdl_acmd.c
 * unit:     yes
 * function: func_02197C4C, func_02197C78, func_02197C9C, func_02197CCC, func_02197D3C, func_02197DA0, func_02197DAC, func_02197DCC, func_02197DE8, func_02197DF4, func_02197E10, func_02197E28, func_02197E44, func_02197E78, func_02197E7C, func_02197EB4, func_02197EDC, func_02197F20, func_02197F5C, func_02197F6C, func_02197F90, func_02197F9C, func_02197FA8, func_02197FB4, func_02197FC0, func_0219800C, func_02198060, func_02198074, func_02198088, func_0219809C, func_021980B0, func_021980C4, func_021980DC, func_021980F0, func_02198104, func_0219811C, func_02198134, func_02198148, func_0219815C, func_02198170, func_02198184, func_02198198, func_021981AC, func_021981C4, func_021981DC, func_021981F0, func_02198208, func_0219821C, func_02198234, func_02198248, func_02198260, func_02198278, func_02198290, func_021982A4, func_021982BC, func_021982D4, func_021982EC, func_02198300, func_02198318, func_0219834C, func_02198380, func_02198390, func_021983A0, func_021983B0, func_021983C0, func_021983D0, func_021983E0, func_021983F0, func_02198400, func_02198410, func_02198420, func_02198430, func_02198440, func_02198450, func_02198460, func_02198470, func_02198480, func_02198490, func_021984A0, func_021984B0, func_021984C0, func_0219852C, func_02198550, func_0219862C, func_02198650, func_02198674, func_02198694, func_021986B8, func_021986D8, func_021986F8, func_02198718, func_02198738, func_02198758, func_0219877C, func_021987A0, func_021987C0, func_021987E0, func_02198804, func_02198824, func_02198848, func_02198868, func_02198888, func_021988AC, func_021988D0, func_021988F4, func_02198918, func_0219893C, func_02198960, func_02198978, func_02198998, func_021989A4, func_021989B0, func_021989BC, func_021989C8, func_021989D4, func_021989E0, func_021989EC, func_02198A10, func_02198A58, func_02198A8C, func_02198AD4, func_02198AE8, func_02198AFC, func_02198B10, func_02198B24, func_02198B38, func_02198B4C, func_02198B80, func_02198BA8, func_02198BB8, func_02198BC8, func_02198BD8, func_02198BE8, func_02198BF8, func_02198C08, func_02198C4C, func_02198CA4, func_02198CB4, func_02198CC4, func_02198CD4, func_02198CE4, func_02198CF4, func_02198D04, func_02198D14, func_02198D24, func_02198D3C, func_02198D4C, func_02198D5C, func_02198D6C, func_02198D7C, func_02198D94, func_02198DA4, func_02198DB4, func_02198DC4, func_02198DD4, func_02198DEC, func_02198DFC, func_02198E0C, func_02198E1C, func_02198E2C, func_02198E44, func_02198E60, func_02198E7C, func_02198E98, func_02198EB0, func_02198EC8, func_02198F20, func_02198F68, func_02198FB0, func_02199034, func_02199050, func_02199070, func_02199088, func_021990A0, func_021990B8, func_021990D4, func_0219912C, func_021991F0, func_02199234, func_02199268, func_02199298, func_021992CC, func_021992FC, func_0219932C, func_02199360, func_02199394, func_021993C8, func_021993FC, func_02199430, func_02199460, func_02199490, func_021994C0, func_021994F0, func_02199520, func_02199550, func_02199584, func_021995B8, func_021995E8, func_02199618, func_0219964C, func_02199680, func_021996B4, func_021996E8, func_0219971C, func_02199750, func_02199784, func_021997B8, func_021997EC, func_02199820, func_02199854, func_02199888, func_02199970, func_02199AEC, func_02199B10, func_02199B38, func_02199B60, func_02199B88, func_02199BAC, func_02199BD8, func_02199C00, func_02199C28, func_02199C50, func_02199C7C, func_02199CA4, func_02199CC8, func_02199CE4, func_02199D00, func_02199D14, func_02199D4C, func_02199D8C, func_02199DB4, func_02199EAC, func_02199EC0, func_02199ED4, func_02199F30, func_02199F50, func_02199F94, func_0219A014, func_0219A028, func_0219A03C, func_0219A058, func_0219A07C
 * address:  0x02197C4C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from ircbattlemenu.c at 0x02197C4C (lane CL131, __FILE__ fldmmdl_acmd.c on 0x02197D3C; 02197C4C..02197D3C work on fldmmdl objects and are called only from fldmmdl code).
 *
 * Joined by lane L138c with the former unit_02198D24.c and fldmmdl_acmd_p01.c (02198D24..0219A07C).
 *
 * symbols:
 *   func_020061E4  0x020061E4  thumb
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02030EAC  0x02030EAC  arm
 *   func_0216D520  0x0216D520  thumb  ov010
 *   func_0219C5D0  0x0219C5D0  thumb  ov021
 *   func_0216D528  0x0216D528  thumb
 *   func_0219D488  0x0219D488  thumb  ov021
 *   func_0216D95C  0x0216D95C  thumb  ov010
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D4D4  0x0216D4D4  thumb  ov010
 *   func_0216DAA0  0x0216DAA0  thumb  ov010
 *   func_0216D758  0x0216D758  thumb  ov010
 *   func_0216DB10  0x0216DB10  thumb  ov010
 *   func_0216DC4C  0x0216DC4C  thumb  ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0216D8B0  0x0216D8B0  thumb  ov010
 *   func_0216D8D0  0x0216D8D0  thumb  ov010
 *   func_0216D8F0  0x0216D8F0  thumb  ov010
 *   func_0216D92C  0x0216D92C  thumb  ov010
 *   func_0216D4F8  0x0216D4F8  thumb  ov010
 *   func_0216D4F4  0x0216D4F4  thumb  ov010
 *   func_0216D514  0x0216D514  thumb  ov010
 *   func_02030DA8  0x02030DA8  arm
 *   d_021DDBE0  0x021DDBE0  data  a4
 *   func_02030EE8  0x02030EE8  arm
 *   func_0216D480  0x0216D480  thumb  ov010
 *   d_021D4A50  0x021D4A50  data  a4
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_0216D454  0x0216D454  thumb  ov010
 *   d_021D5D6C  0x021D5D6C  data  a4
 *   func_0216D7C4  0x0216D7C4  thumb  ov010
 *   func_0216D7D4  0x0216D7D4  thumb  ov010
 *   func_0216D57C  0x0216D57C  thumb  ov010
 *   func_0216D570  0x0216D570  thumb  ov010
 *   func_0216D7C0  0x0216D7C0  thumb  ov010
 *   func_0216D7C8  0x0216D7C8  thumb  ov010
 *   d_021D624C  0x021D624C  data  a4
 *   d_021D5F58  0x021D5F58  data  a4
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_02163F10  0x02163F10  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb
 *   func_0216D6BC  0x0216D6BC  thumb  ov010
 *   func_02163E7C  0x02163E7C  thumb  ov010
 *   func_0216D60C  0x0216D60C  thumb  ov010
 *   func_0216D6D4  0x0216D6D4  thumb  ov010
 *   func_02163FC0  0x02163FC0  thumb  ov010
 *   func_02164010  0x02164010  thumb  ov010
 *   d_021DDBD4  0x021DDBD4  data   ov021  a4
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 *   func_0216D548  0x0216D548  thumb  ov010
 *   func_0216D550  0x0216D550  thumb  ov010
 *   func_0216D534  0x0216D534  thumb  ov010
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021BB528  0x021BB528  thumb  ov021
 *   func_021BB5C8  0x021BB5C8  thumb  ov021
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_02198C4C  0x02198C4C  thumb
 *   func_02198C08  0x02198C08  thumb
 *   func_02198E44  0x02198E44  thumb
 *   func_02198E60  0x02198E60  thumb
 *   func_0216D7A8  0x0216D7A8  thumb  ov010
 *   func_0219C9DC  0x0219C9DC  thumb  ov021
 *   func_020508EC  0x020508EC  arm
 *   func_0219BF48  0x0219BF48  thumb  ov021
 *   func_021D04A4  0x021D04A4  thumb  ov021
 *   func_021D04C4  0x021D04C4  thumb  ov021
 *   func_0219BF3C  0x0219BF3C  thumb  ov021
 *   func_0219BF54  0x0219BF54  thumb  ov021
 *   d_021D4C1C  0x021D4C1C  data   a4
 *   func_0216D600  0x0216D600  thumb  ov010
 *   func_0216DA70  0x0216DA70  thumb  ov010
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D80C  0x0216D80C  thumb  ov010
 *   func_0216D854  0x0216D854  thumb  ov010
 *   func_0216D818  0x0216D818  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0216D824  0x0216D824  thumb  ov010
 *   func_0216D848  0x0216D848  thumb  ov010
 *   func_0216D860  0x0216D860  thumb  ov010
 *   func_0216D87C  0x0216D87C  thumb  ov010
 *   func_02163F8C  0x02163F8C  thumb  ov010
 *   d_021D4B44  0x021D4B44  data  ov021  a4
 *   d_021D4204  0x021D4204  data  ov021  a4
 *   d_021D4C04  0x021D4C04  data  a4
 *   d_021D41E0  0x021D41E0  data  ov021  a4
 *   d_021D4210  0x021D4210  data  a4
 *   d_021D4C10  0x021D4C10  data  a4
 *   d_021D4648  0x021D4648  data  a4
 *   d_021D4BF8  0x021D4BF8  data  a4
 *   d_021D4BEC  0x021D4BEC  data  a4
 *   d_021D4BE0  0x021D4BE0  data  a4
 *   d_021D4BD4  0x021D4BD4  data  a4
 *   d_021D4BC8  0x021D4BC8  data  a4
 *   d_021D4BBC  0x021D4BBC  data  a4
 *   d_021D4BB0  0x021D4BB0  data  a4
 *   d_021D4BA4  0x021D4BA4  data  a4
 *   d_021D4B98  0x021D4B98  data  a4
 *   d_021D4B8C  0x021D4B8C  data  a4
 *   d_021D4B80  0x021D4B80  data  a4
 *   d_021D4B74  0x021D4B74  data  a4
 *   d_021D4B68  0x021D4B68  data  a4
 *   d_021D4B5C  0x021D4B5C  data  a4
 *   d_021D4B50  0x021D4B50  data  a4
 *   d_021D45E8  0x021D45E8  data  a4
 *   d_021D4B38  0x021D4B38  data  a4
 *   d_021D4B2C  0x021D4B2C  data  a4
 *   d_021D4B20  0x021D4B20  data  a4
 *   d_021D4B14  0x021D4B14  data  a4
 *   d_021D4B08  0x021D4B08  data  a4
 *   d_021D4AFC  0x021D4AFC  data  a4
 *   d_021D4AF0  0x021D4AF0  data  a4
 *   d_021D4AE4  0x021D4AE4  data  a4
 *   d_021D4AD8  0x021D4AD8  data  a4
 *   _s32_div_f  0x0209C0A4  arm
 *   func_0216D89C  0x0216D89C  thumb  ov010
 *   func_0219FC68  0x0219FC68  thumb  ov021
 *   func_0216D598  0x0216D598  thumb  ov010
 *   d_021D4ACC  0x021D4ACC  data  a4
 *   func_0219FCC0  0x0219FCC0  thumb  ov021
 *   func_0219FE64  0x0219FE64  thumb  ov021
 *   func_0219FE20  0x0219FE20  thumb  ov021
 *   func_0216D684  0x0216D684  thumb  ov010
 *   func_0216DA50  0x0216DA50  thumb
 *   d_021D4FA4  0x021D4FA4  data  a4
 *   func_0216D69C  0x0216D69C  thumb  ov010
 *   func_0216D5A8  0x0216D5A8  thumb  ov010
 *   func_02164168  0x02164168  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D5A0  0x0216D5A0  thumb  ov010
 *   d_021D5074  0x021D5074  data  a4
 *   func_0216DA7C  0x0216DA7C  thumb  ov010
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D438  0x0216D438  thumb  ov010
 *   func_02197EDC  0x02197EDC  thumb  ov021
 *   func_021639C0  0x021639C0  thumb  ov010
 *   func_0216DA44  0x0216DA44  thumb  ov010
 *   func_0216D7E8  0x0216D7E8  thumb  ov010
 *   func_0216D7F8  0x0216D7F8  thumb  ov010
 *   func_0216D660  0x0216D660  thumb  ov010
 *   func_0216D66C  0x0216D66C  thumb  ov010
 *   func_021641E8  0x021641E8  thumb  ov010
 *   func_021641F8  0x021641F8  thumb  ov010
 *   d_021D4DE8  0x021D4DE8  data  a4
 *   d_021D5024  0x021D5024  data  a4
 *   d_021D5038  0x021D5038  data  a4
 *   d_021D4DB8  0x021D4DB8  data  a4
 *   d_021D504C  0x021D504C  data  a4
 *   d_021D5060  0x021D5060  data  a4
 *   func_0216D5D4  0x0216D5D4  thumb  ov010
 *   func_021642A4  0x021642A4  thumb  ov010
 *   d_021D4D60  0x021D4D60  data  a4
 *   func_0216D608  0x0216D608  thumb  ov010
 *   d_021D4D04  0x021D4D04  data  a4
 *   d_021D4D78  0x021D4D78  data  a4
 *   func_0216D63C  0x0216D63C  thumb  ov010
 *   func_021AE198  0x021AE198  thumb  ov021
 *   func_0216E0E8  0x0216E0E8  thumb  ov010
 *   d_021D4F90  0x021D4F90  data    a2
 *   func_0203630C  0x0203630C  arm
 *   func_0216DEE0  0x0216DEE0  thumb  ov010
 *   func_020362DC  0x020362DC  arm
 *   func_020056EC  0x020056EC  thumb
 *   d_021D50F8  0x021D50F8  data  a4
 *   func_021642B4  0x021642B4  thumb  ov010
 *   d_021D4FEC  0x021D4FEC  data  a4
 *   d_021D4FCC  0x021D4FCC  data    a4
 *   data_021D5278  0x021D5278  data   ov021  a4
 *   d_021D52CC  0x021D52CC  data  a4
 *   d_021D5320  0x021D5320  data  a4
 *   func_0216D804  0x0216D804  thumb  ov010
 *   func_0216D81C  0x0216D81C  thumb  ov010
 *   d_021D4A44  0x021D4A44  data  a4
 *   d_021D4A68  0x021D4A68  data  a4
 *   d_021D4A80  0x021D4A80  data  a4
 *   d_021D4A9C  0x021D4A9C  data  a4
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

#include "../ov010/fldmmdl_types.h"

#define NULL ((void *)0)

/* Directions of a field model (Mmdl.dirDisp, Mmdl.dirMove). */
#define MMDL_DIR_UP    0
#define MMDL_DIR_DOWN  1
#define MMDL_DIR_LEFT  2
#define MMDL_DIR_RIGHT 3

/* Mmdl.statusBit bit 0x10: pauses the model's animation. */
#define MMDL_STABIT_PAUSE_ANIME 0x0010

/* MmdlSys.statusBit bit 0x04: the model draw procedures are suspended. */
#define MMDLSYS_STABIT_DRAW_SUSPEND 0x0004

/* Draw status of a model (Mmdl.drawStatus) while an animation command runs. */
#define MMDL_DRAWSTA_STOP     0
#define MMDL_DRAWSTA_WALK_32F 1
#define MMDL_DRAWSTA_WALK_16F 2
#define MMDL_DRAWSTA_WALK_8F  3
#define MMDL_DRAWSTA_WALK_4F  4
#define MMDL_DRAWSTA_WALK_2F  5
#define MMDL_DRAWSTA_WALK_6F  6
#define MMDL_DRAWSTA_WALK_3F  7
#define MMDL_DRAWSTA_WALK_7F  8
#define MMDL_DRAWSTA_WALK_12F 9
#define MMDL_DRAWSTA_DASH_4F  0x0A
#define MMDL_DRAWSTA_DASH_6F  0x0B
#define MMDL_DRAWSTA_DASH_2F  0x0C

/* Animation command code 0xFF: none running. 0xFE ends a command list. */
#define MMDL_ACMD_NONE     0xFF
#define MMDL_ACMD_LIST_END 0xFE

/* One grid is 0x10000 in position units; a walk of N frames moves 1/N grid per frame. */
#define ACMD_GRID_FIXED 0x10000
#define ACMD_GRID_SPEED(frames) (ACMD_GRID_FIXED / (frames))

/* Sound effect numbers played by jump commands. */
#define SE_JUMP 0x55E
#define SE_FALL 0x676
#define SE_LAND 0x67B
#define SE_DASH_START   0x7B7
#define SE_FLY_FLAP_A   0x7E5
#define SE_FLY_FLAP_B   0x7E6
#define SE_FLY_TAKEOFF  0x7E7

/* Object codes of the flying models (draw animation lookups of fldmmdl_draw.c). */
#define MMDL_OBJCODE_FLY_A 0xD3
#define MMDL_OBJCODE_FLY_B 0xDD

/* Axis numbers of a jump or step command: the component of the position vector. */
#define ACMD_AXIS_X 0
#define ACMD_AXIS_Y 1
#define ACMD_AXIS_Z 2

/* Flight: height speed per frame and the frames before the model starts to rise. */
#define ACMD_FLY_SPEED           0x2000
#define ACMD_FLY_TAKEOFF_FRAMES  0x5F

/* One entry of a command list: run the command code, then count more times. */
typedef struct MmdlAcmdListEntry {
    u16 code;
    u16 count;
} MmdlAcmdListEntry;

/* Work of the command list task (0x14 bytes). */
typedef struct MmdlAcmdListWork {
    int state;
    int endFlag;
    int cmdIndex;
    Mmdl *mmdl;
    const MmdlAcmdListEntry *list;
} MmdlAcmdListWork;

/* Per-command work kept in Mmdl.moveCmdWork (0x10 bytes). */
typedef struct AcmdWalkWork {
    u16 drawStatus;
    s16 framesLeft;
    u32 dir;
    u32 speed;
} AcmdWalkWork;

typedef struct AcmdJumpWork {
    int speed;
    int progress;       /* distance moved inside the current grid */
    u16 heightStep;
    u16 height;
    s8 dir;
    s8 framesLeft;
    u8 drawStatus;
    s8 heightTable;
} AcmdJumpWork;

typedef struct AcmdWaitWork {
    u32 framesLeft;
} AcmdWaitWork;

typedef struct AcmdRiseWork {
    int height;
    int step;
} AcmdRiseWork;

typedef struct AcmdMarkWork {
    u32 markType;
    u32 effect;
} AcmdMarkWork;

typedef struct AcmdWalkTableWork {
    u16 dir;
    u16 drawStatus;
    s16 frames;
    s16 frameIndex;
} AcmdWalkTableWork;

/* Work of the anime start commands (4 bytes, never read). */
typedef struct AcmdAnimeWork {
    u32 state;
} AcmdAnimeWork;

/* Work of the commands that count frames. */
typedef struct AcmdCounterWork {
    int count;
} AcmdCounterWork;

/* Work of the hide off hop: index into height table 0. */
typedef struct AcmdHideWork {
    u32 heightIndex;
} AcmdHideWork;

/* Work of the walk in place commands. */
typedef struct AcmdStayWork {
    u16 elapsed;
    u16 frames;
} AcmdStayWork;

/* Work of the step commands (0x10 bytes): frames left and the position step per frame. */
typedef struct AcmdStepWork {
    int framesLeft;
    MmdlVec step;
} AcmdStepWork;

/* Offsets of the bounce, one per frame. */
typedef struct AcmdBounceTable {
    int height[10];
} AcmdBounceTable;

/* Work of the hop commands (0x10 bytes). */
typedef struct AcmdHopWork {
    u8 frames;          /* frames left */
    u8 arcAxis;         /* axis of the rise (height table 1) */
    u8 moveAxis;        /* axis of the move */
    u8 negate;          /* nonzero: the rise goes down */
    int speed;          /* position units per frame along the move axis */
    int progress;       /* distance moved inside the current grid */
    u16 angle;          /* index into the height table, 0x100 per entry */
    u16 angleStep;
} AcmdHopWork;

/* Work of the flight (0x10 bytes). */
typedef struct AcmdFlyWork {
    int height;
    int speed;
    u16 elapsed;
    u8 lastFrame;
    u8 padding[5];
} AcmdFlyWork;

/* Work of the wait before the flight (6 bytes). */
typedef struct AcmdFlyReadyWork {
    u16 elapsed;
    u8 lastFrame;
    u8 padding[3];
} AcmdFlyReadyWork;

extern void func_02163E7C(Mmdl *mmdl, int dir);
extern void func_02163F10(Mmdl *mmdl);
extern void func_02163FC0(Mmdl *mmdl, int dir, int amount);
extern void func_02164010(Mmdl *mmdl);
extern int func_0216D3CC(Mmdl *mmdl);
extern void func_0216D410(Mmdl *mmdl, u16 code);
extern int func_0216D454(Mmdl *mmdl);
extern int func_0216D480(Mmdl *mmdl);
extern u32 func_0216D4D4(MmdlSys *sys, u32 bit);
extern u16 func_0216D4F4(MmdlSys *sys);
extern u32 func_0216D4F8(MmdlSys *sys);
extern void *func_0216D514(MmdlSys *sys);
extern void *func_0216D520(MmdlSys *sys);
extern void *func_0216D528(MmdlSys *sys);
extern void *func_0216D534(MmdlSys *sys);
extern void func_0216D548(Mmdl *mmdl, u32 bit);
extern void func_0216D550(Mmdl *mmdl, u32 bit);
extern u32 func_0216D55C(Mmdl *mmdl, u32 bit);
extern void func_0216D568(Mmdl *mmdl, u32 bit);
extern void func_0216D570(Mmdl *mmdl, u32 bit);
extern u32 func_0216D57C(Mmdl *mmdl, u32 bit);
extern void func_0216D5E0(Mmdl *mmdl, int dir);
extern void func_0216D60C(Mmdl *mmdl, u16 dir);
extern void func_0216D674(Mmdl *mmdl, u16 drawStatus);
extern MmdlSys *func_0216D67C(Mmdl *mmdl);
extern void *func_0216D6BC(Mmdl *mmdl, int size);
extern void *func_0216D6D4(Mmdl *mmdl);
extern void func_0216D758(Mmdl *mmdl);
extern void func_0216D7C0(Mmdl *mmdl, u16 code);
extern u16 func_0216D7C4(Mmdl *mmdl);
extern void func_0216D7C8(Mmdl *mmdl, u16 seq);
extern int func_0216D7CC(Mmdl *mmdl);
extern u16 func_0216D7D4(Mmdl *mmdl);
extern void func_0216D88C(const Mmdl *mmdl, MmdlVec *out);
extern void func_0216D8B0(Mmdl *mmdl, MmdlVec *out);
extern void func_0216D8C0(Mmdl *mmdl, const MmdlVec *offset);
extern void func_0216D8D0(Mmdl *mmdl, MmdlVec *out);
extern void func_0216D8F0(Mmdl *mmdl, MmdlVec *out);
extern void func_0216D92C(Mmdl *mmdl, MmdlVec *out);
extern void func_0216D95C(MmdlSys *sys, int flag);
extern int func_0216DAA0(Mmdl *mmdl);
extern int func_0216DB10(Mmdl *mmdl);
extern int func_0216DC4C(Mmdl *mmdl);

extern void func_0219C5D0(MmdlSys *sys);
extern void func_0219D488(MmdlSys *sys);
extern void *func_02188CD0(void *fieldMap);
extern u32 func_021BB528(void *fieldEffectSys, Mmdl *mmdl, u32 type, u32 sePlay);
extern int func_021BB5C8(u32 effect);
extern void func_021AC154(u32 effect);

extern void func_020061E4(u32 se);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern int func_020307B0(void *mem);
extern void func_02030DA8(void *tcbSys, void (*func)(void *, MmdlAcmdListWork *), void *work, u32 priority);
extern void func_02030EAC(void *tcb);
extern void *func_02030EE8(void *tcb);

extern u8 d_021DDBE0;
extern int (*const d_021D4A50[])(MmdlAcmdListWork *);
extern int *d_021D5D6C[];
extern int (**const d_021D624C[])(Mmdl *);
extern int (**const d_021D5F58[])(Mmdl *);
extern int *d_021DDBD4[];
extern void func_02163F8C(Mmdl *mmdl, const MmdlVec *step);
extern u16 func_0216D598(Mmdl *mmdl);
extern void func_0216D600(Mmdl *mmdl, u16 dir);
extern int func_0216D7A8(Mmdl *mmdl, u32 kind);
extern void func_0216D80C(Mmdl *mmdl, int grid);
extern int func_0216D83C(Mmdl *mmdl);
extern void func_0216D818(Mmdl *mmdl, int grid);
extern int func_0216D854(Mmdl *mmdl);
extern void func_0216D824(Mmdl *mmdl, int grid);
extern int func_0216D86C(Mmdl *mmdl);
extern void func_0216D848(Mmdl *mmdl, s16 amount);
extern void func_0216D860(Mmdl *mmdl, s16 amount);
extern void func_0216D87C(Mmdl *mmdl, s16 amount);
extern void func_0216D89C(Mmdl *mmdl, const MmdlVec *pos);
extern void func_0216DA70(Mmdl *mmdl);
extern void *func_0219C9DC(void *blActCont);
extern int func_020508EC(void *blActSys, int animeId, u16 *animeFlag);
extern u32 func_0219BF48(Mmdl *mmdl);
extern void func_0219BF3C(Mmdl *mmdl, u32 effect);
extern void func_0219BF54(Mmdl *mmdl);
extern void func_021D04A4(u32 effect);
extern int func_021D04C4(u32 effect);
extern int func_0219FC68(Mmdl *mmdl, u16 *animeState, u16 *animeFrame);
extern int func_0219FCC0(Mmdl *mmdl, u16 *animeState, u16 *animeFrame);
extern void func_0219FE64(Mmdl *mmdl);
extern int func_0219FE20(Mmdl *mmdl);

extern const u32 d_021D4A44[];
extern const u32 d_021D4A68[];
extern const u32 d_021D4A80[];
extern const u32 d_021D4A9C[];
extern const AcmdBounceTable d_021D4C1C;
extern const MmdlVec d_021D41E0;
extern const MmdlVec d_021D4204;
extern const MmdlVec d_021D4210;
extern const MmdlVec d_021D45E8;
extern const MmdlVec d_021D4648;
extern const MmdlVec d_021D4ACC;
extern const MmdlVec d_021D4AD8;
extern const MmdlVec d_021D4AE4;
extern const MmdlVec d_021D4AF0;
extern const MmdlVec d_021D4AFC;
extern const MmdlVec d_021D4B08;
extern const MmdlVec d_021D4B14;
extern const MmdlVec d_021D4B20;
extern const MmdlVec d_021D4B2C;
extern const MmdlVec d_021D4B38;
extern const MmdlVec d_021D4B44;
extern const MmdlVec d_021D4B50;
extern const MmdlVec d_021D4B5C;
extern const MmdlVec d_021D4B68;
extern const MmdlVec d_021D4B74;
extern const MmdlVec d_021D4B80;
extern const MmdlVec d_021D4B8C;
extern const MmdlVec d_021D4B98;
extern const MmdlVec d_021D4BA4;
extern const MmdlVec d_021D4BB0;
extern const MmdlVec d_021D4BBC;
extern const MmdlVec d_021D4BC8;
extern const MmdlVec d_021D4BD4;
extern const MmdlVec d_021D4BE0;
extern const MmdlVec d_021D4BEC;
extern const MmdlVec d_021D4BF8;
extern const MmdlVec d_021D4C04;
extern const MmdlVec d_021D4C10;

int func_02197F20(Mmdl *mmdl, u32 code, u32 seq);
void func_02197DCC(void *tcb, MmdlAcmdListWork *work);

void func_02197C4C(MmdlSys *mmdlSys)
{
    if (func_0216D520(mmdlSys) != NULL) {
        func_0219C5D0(mmdlSys);
    }
    if (func_0216D528(mmdlSys) != NULL) {
        func_0219D488(mmdlSys);
    }
    func_0216D95C(mmdlSys, 0);
}

void func_02197C78(Mmdl *mmdl)
{
    if (func_0216D4D4(func_0216D67C(mmdl), MMDLSYS_STABIT_DRAW_SUSPEND) == 0 && func_0216DAA0(mmdl) != 0) {
        func_0216D758(mmdl);
    }
}

int func_02197C9C(Mmdl *mmdl)
{
    if (func_0216DB10(mmdl) != 0) {
        if (func_0216DC4C(mmdl) == 0) {
            return 1;
        }
    }
    if (func_0216D55C(mmdl, MMDL_STABIT_PAUSE_ANIME) != 0) {
        return 1;
    }
    return 0;
}

/* Draw position: position plus the draw, outside draw, attribute and model offsets. */
void func_02197CCC(Mmdl *mmdl, MmdlVec *out)
{
    MmdlVec pos;
    MmdlVec drawOffset;
    MmdlVec drawOffsetOutside;
    MmdlVec attrOffset;
    MmdlVec modelOffset;

    func_0216D88C(mmdl, &pos);
    func_0216D8B0(mmdl, &drawOffset);
    func_0216D8D0(mmdl, &drawOffsetOutside);
    func_0216D8F0(mmdl, &attrOffset);
    func_0216D92C(mmdl, &modelOffset);
    out->x = pos.x + drawOffset.x + drawOffsetOutside.x + attrOffset.x + modelOffset.x;
    out->y = pos.y + drawOffset.y + drawOffsetOutside.y + attrOffset.y + modelOffset.y;
    out->z = pos.z + drawOffset.z + drawOffsetOutside.z + attrOffset.z + modelOffset.z;
}

/* Starts a task that runs a command list: entries of (code, count), ended by code 0xFE. */
void func_02197D3C(Mmdl *mmdl, const MmdlAcmdListEntry *list)
{
    MmdlSys *mmdlSys;
    MmdlAcmdListWork *work;
    u32 priority;

    mmdlSys = func_0216D67C(mmdl);
    work = func_02030734((u16)(0x8000 | (func_0216D4F8(mmdlSys) & 0x7fff)), sizeof(MmdlAcmdListWork), 1, (const char *)&d_021DDBE0, 0x115);
    priority = func_0216D4F4(func_0216D67C(mmdl)) - 2;
    func_02030DA8(func_0216D514(mmdlSys), func_02197DCC, work, priority);
    work->mmdl = mmdl;
    work->list = list;
}

int func_02197DA0(void *tcb)
{
    return ((MmdlAcmdListWork *)func_02030EE8(tcb))->endFlag;
}

void func_02197DAC(void *tcb)
{
    MmdlAcmdListWork *work;

    work = func_02030EE8(tcb);
    func_0216D480(work->mmdl);
    func_020307B0(work);
    func_02030EAC(tcb);
}

void func_02197DCC(void *tcb, MmdlAcmdListWork *work)
{
    while (d_021D4A50[work->state](work) == 1) {
    }
}

int func_02197DE8(MmdlAcmdListWork *work)
{
    work->cmdIndex = 0;
    work->state = 1;
    return 1;
}

int func_02197DF4(MmdlAcmdListWork *work)
{
    if (func_0216D3CC(work->mmdl) == 0) {
        return 0;
    }
    work->state = 2;
    return 1;
}

int func_02197E10(MmdlAcmdListWork *work)
{
    func_0216D410(work->mmdl, work->list->code);
    work->state = 3;
    return 0;
}

int func_02197E28(MmdlAcmdListWork *work)
{
    if (func_0216D454(work->mmdl) == 0) {
        return 0;
    }
    work->state = 4;
    return 1;
}

int func_02197E44(MmdlAcmdListWork *work)
{
    const MmdlAcmdListEntry *entry = work->list;
    int index = ++work->cmdIndex;
    if (index < entry->count) {
        work->state = 1;
        return 1;
    }
    work->list = entry + 1;
    if (entry[1].code != MMDL_ACMD_LIST_END) {
        work->state = 0;
        return 1;
    }
    work->endFlag = 1;
    work->state = 5;
    return 0;
}

int func_02197E78(void)
{
    return 0;
}

/* Finds the code in one of the code groups and returns the group member at the index. */
int func_02197E7C(int index, int code)
{
    int i;
    int **group;
    int *members;
    group = d_021D5D6C;
    do {
        members = *group;
        for (i = 0; i < 4; i++) {
            if (code == members[i]) {
                return (u16)members[index];
            }
        }
        group++;
    } while (*group != 0);
    return code;
}

void func_02197EB4(Mmdl *mmdl)
{
    u32 code;
    do {
        code = func_0216D7C4(mmdl);
        if (code == MMDL_ACMD_NONE) {
            return;
        }
    } while (func_02197F20(mmdl, code, func_0216D7D4(mmdl)) != 0);
}

u32 func_02197EDC(Mmdl *mmdl)
{
    if (func_0216D7C4(mmdl) != MMDL_ACMD_NONE) {
        func_02197EB4(mmdl);
        if (func_0216D57C(mmdl, MMDL_MOVEBIT_ACMD_END) == 0) {
            return 0;
        }
    }
    func_0216D570(mmdl, MMDL_MOVEBIT_ACMD_END);
    func_0216D7C0(mmdl, MMDL_ACMD_NONE);
    func_0216D7C8(mmdl, 0);
    return 1;
}

int func_02197F20(Mmdl *mmdl, u32 code, u32 seq)
{
    if (func_0216D55C(mmdl, MMDL_STABIT_RAIL_MOVE) != 0) {
        return d_021D624C[code][seq](mmdl);
    }
    return d_021D5F58[code][seq](mmdl);
}

int func_02197F5C(Mmdl *mmdl)
{
    func_0216D568(mmdl, MMDL_MOVEBIT_ACMD_END);
    return 0;
}

int func_02197F6C(Mmdl *mmdl, u32 dir)
{
    func_0216D5E0(mmdl, (u16)dir);
    func_0216D674(mmdl, 0);
    func_02163F10(mmdl);
    return func_0216D7CC(mmdl);
}

u32 func_02197F90(Mmdl *mmdl)
{
    func_02197F6C(mmdl, MMDL_DIR_UP);
    return 1;
}

u32 func_02197F9C(Mmdl *mmdl)
{
    func_02197F6C(mmdl, MMDL_DIR_DOWN);
    return 1;
}

u32 func_02197FA8(Mmdl *mmdl)
{
    func_02197F6C(mmdl, MMDL_DIR_LEFT);
    return 1;
}

u32 func_02197FB4(Mmdl *mmdl)
{
    func_02197F6C(mmdl, MMDL_DIR_RIGHT);
    return 1;
}

void func_02197FC0(Mmdl *mmdl, u32 dir, u32 speed, u16 frames, u16 drawStatus)
{
    AcmdWalkWork *work;
    work = func_0216D6BC(mmdl, sizeof(AcmdWalkWork));
    work->drawStatus = drawStatus;
    work->framesLeft = frames;
    work->dir = dir;
    work->speed = speed;
    func_02163E7C(mmdl, (u16)dir);
    func_0216D60C(mmdl, dir);
    func_0216D674(mmdl, drawStatus);
    func_0216D568(mmdl, MMDL_MOVEBIT_MOVE_START);
    func_0216D7CC(mmdl);
}

u32 func_0219800C(Mmdl *mmdl)
{
    AcmdWalkWork *work;
    work = func_0216D6D4(mmdl);
    func_02163FC0(mmdl, (u16)work->dir, work->speed);
    func_02164010(mmdl);
    work->framesLeft = work->framesLeft - 1;
    if (work->framesLeft > 0) {
        return 0;
    }
    func_0216D568(mmdl, MMDL_MOVEBIT_MOVE_END | MMDL_MOVEBIT_ACMD_END);
    func_02163F10(mmdl);
    func_0216D674(mmdl, 0);
    func_0216D7CC(mmdl);
    return 0;
}

int func_02198060(Mmdl *mmdl)
{
    func_02197FC0(mmdl, MMDL_DIR_UP, ACMD_GRID_SPEED(32), 32, MMDL_DRAWSTA_WALK_32F);
    return 1;
}

int func_02198074(Mmdl *mmdl)
{
    func_02197FC0(mmdl, MMDL_DIR_DOWN, ACMD_GRID_SPEED(32), 32, MMDL_DRAWSTA_WALK_32F);
    return 1;
}

int func_02198088(Mmdl *mmdl)
{
    func_02197FC0(mmdl, MMDL_DIR_LEFT, ACMD_GRID_SPEED(32), 32, MMDL_DRAWSTA_WALK_32F);
    return 1;
}

int func_0219809C(Mmdl *mmdl)
{
    func_02197FC0(mmdl, MMDL_DIR_RIGHT, ACMD_GRID_SPEED(32), 32, MMDL_DRAWSTA_WALK_32F);
    return 1;
}

int func_021980B0(Mmdl *mmdl)
{
    func_02197FC0(mmdl, MMDL_DIR_UP, ACMD_GRID_SPEED(16), 16, MMDL_DRAWSTA_WALK_16F);
    return 1;
}

int func_021980C4(Mmdl *mmdl)
{
    func_02197FC0(mmdl, MMDL_DIR_DOWN, ACMD_GRID_SPEED(16), 16, MMDL_DRAWSTA_WALK_16F);
    return 1;
}

int func_021980DC(Mmdl *mmdl)
{
    func_02197FC0(mmdl, MMDL_DIR_LEFT, ACMD_GRID_SPEED(16), 16, MMDL_DRAWSTA_WALK_16F);
    return 1;
}

int func_021980F0(Mmdl *mmdl)
{
    func_02197FC0(mmdl, MMDL_DIR_RIGHT, ACMD_GRID_SPEED(16), 16, MMDL_DRAWSTA_WALK_16F);
    return 1;
}

int func_02198104(Mmdl *mmdl)
{
    func_02197FC0(mmdl, MMDL_DIR_UP, ACMD_GRID_SPEED(8), 8, MMDL_DRAWSTA_WALK_8F);
    return 1;
}

int func_0219811C(Mmdl *mmdl)
{
    func_02197FC0(mmdl, MMDL_DIR_DOWN, ACMD_GRID_SPEED(8), 8, MMDL_DRAWSTA_WALK_8F);
    return 1;
}

int func_02198134(Mmdl *mmdl)
{
    func_02197FC0(mmdl, MMDL_DIR_LEFT, ACMD_GRID_SPEED(8), 8, MMDL_DRAWSTA_WALK_8F);
    return 1;
}

int func_02198148(Mmdl *mmdl)
{
    func_02197FC0(mmdl, MMDL_DIR_RIGHT, ACMD_GRID_SPEED(8), 8, MMDL_DRAWSTA_WALK_8F);
    return 1;
}

int func_0219815C(Mmdl *mmdl)
{
    func_02197FC0(mmdl, MMDL_DIR_UP, ACMD_GRID_SPEED(4), 4, MMDL_DRAWSTA_WALK_4F);
    return 1;
}

int func_02198170(Mmdl *mmdl)
{
    func_02197FC0(mmdl, MMDL_DIR_DOWN, ACMD_GRID_SPEED(4), 4, MMDL_DRAWSTA_WALK_4F);
    return 1;
}

int func_02198184(Mmdl *mmdl)
{
    func_02197FC0(mmdl, MMDL_DIR_LEFT, ACMD_GRID_SPEED(4), 4, MMDL_DRAWSTA_WALK_4F);
    return 1;
}

int func_02198198(Mmdl *mmdl)
{
    func_02197FC0(mmdl, MMDL_DIR_RIGHT, ACMD_GRID_SPEED(4), 4, MMDL_DRAWSTA_WALK_4F);
    return 1;
}

int func_021981AC(Mmdl *mmdl)
{
    func_02197FC0(mmdl, MMDL_DIR_UP, ACMD_GRID_SPEED(2), 2, MMDL_DRAWSTA_WALK_2F);
    return 1;
}

int func_021981C4(Mmdl *mmdl)
{
    func_02197FC0(mmdl, MMDL_DIR_DOWN, ACMD_GRID_SPEED(2), 2, MMDL_DRAWSTA_WALK_2F);
    return 1;
}

int func_021981DC(Mmdl *mmdl)
{
    func_02197FC0(mmdl, MMDL_DIR_LEFT, ACMD_GRID_SPEED(2), 2, MMDL_DRAWSTA_WALK_2F);
    return 1;
}

int func_021981F0(Mmdl *mmdl)
{
    func_02197FC0(mmdl, MMDL_DIR_RIGHT, ACMD_GRID_SPEED(2), 2, MMDL_DRAWSTA_WALK_2F);
    return 1;
}

int func_02198208(Mmdl *mmdl)
{
    func_02197FC0(mmdl, MMDL_DIR_UP, ACMD_GRID_SPEED(1), 1, MMDL_DRAWSTA_STOP);
    return 1;
}

int func_0219821C(Mmdl *mmdl)
{
    func_02197FC0(mmdl, MMDL_DIR_DOWN, ACMD_GRID_SPEED(1), 1, MMDL_DRAWSTA_STOP);
    return 1;
}

int func_02198234(Mmdl *mmdl)
{
    func_02197FC0(mmdl, MMDL_DIR_LEFT, ACMD_GRID_SPEED(1), 1, MMDL_DRAWSTA_STOP);
    return 1;
}

int func_02198248(Mmdl *mmdl)
{
    func_02197FC0(mmdl, MMDL_DIR_RIGHT, ACMD_GRID_SPEED(1), 1, MMDL_DRAWSTA_STOP);
    return 1;
}

int func_02198260(Mmdl *mmdl)
{
    func_02197FC0(mmdl, MMDL_DIR_UP, ACMD_GRID_SPEED(4), 4, MMDL_DRAWSTA_DASH_4F);
    return 1;
}

int func_02198278(Mmdl *mmdl)
{
    func_02197FC0(mmdl, MMDL_DIR_DOWN, ACMD_GRID_SPEED(4), 4, MMDL_DRAWSTA_DASH_4F);
    return 1;
}

int func_02198290(Mmdl *mmdl)
{
    func_02197FC0(mmdl, MMDL_DIR_LEFT, ACMD_GRID_SPEED(4), 4, MMDL_DRAWSTA_DASH_4F);
    return 1;
}

int func_021982A4(Mmdl *mmdl)
{
    func_02197FC0(mmdl, MMDL_DIR_RIGHT, ACMD_GRID_SPEED(4), 4, MMDL_DRAWSTA_DASH_4F);
    return 1;
}

int func_021982BC(Mmdl *mmdl)
{
    func_02197FC0(mmdl, MMDL_DIR_UP, ACMD_GRID_SPEED(16), 16, MMDL_DRAWSTA_WALK_2F);
    return 1;
}

int func_021982D4(Mmdl *mmdl)
{
    func_02197FC0(mmdl, MMDL_DIR_DOWN, ACMD_GRID_SPEED(16), 16, MMDL_DRAWSTA_WALK_2F);
    return 1;
}

int func_021982EC(Mmdl *mmdl)
{
    func_02197FC0(mmdl, MMDL_DIR_LEFT, ACMD_GRID_SPEED(16), 16, MMDL_DRAWSTA_WALK_2F);
    return 1;
}

int func_02198300(Mmdl *mmdl)
{
    func_02197FC0(mmdl, MMDL_DIR_RIGHT, ACMD_GRID_SPEED(16), 16, MMDL_DRAWSTA_WALK_2F);
    return 1;
}

void func_02198318(Mmdl *mmdl, u32 dir, u16 frames, u16 drawStatus)
{
    AcmdWalkWork *work;
    work = func_0216D6BC(mmdl, sizeof(AcmdWalkWork));
    work->drawStatus = drawStatus;
    work->framesLeft = frames;
    func_0216D5E0(mmdl, (u16)dir);
    func_0216D674(mmdl, drawStatus);
    func_02163F10(mmdl);
    func_0216D7CC(mmdl);
}

int func_0219834C(Mmdl *mmdl)
{
    AcmdWalkWork *work;
    work = func_0216D6D4(mmdl);
    work->framesLeft--;
    if (work->framesLeft > 0) {
        return 0;
    }
    func_0216D568(mmdl, MMDL_MOVEBIT_ACMD_END);
    func_0216D674(mmdl, 0);
    func_0216D7CC(mmdl);
    return 0;
}

u32 func_02198380(Mmdl *mmdl)
{
    func_02198318(mmdl, MMDL_DIR_UP, 32, MMDL_DRAWSTA_WALK_32F);
    return 1;
}

u32 func_02198390(Mmdl *mmdl)
{
    func_02198318(mmdl, MMDL_DIR_DOWN, 32, MMDL_DRAWSTA_WALK_32F);
    return 1;
}

u32 func_021983A0(Mmdl *mmdl)
{
    func_02198318(mmdl, MMDL_DIR_LEFT, 32, MMDL_DRAWSTA_WALK_32F);
    return 1;
}

u32 func_021983B0(Mmdl *mmdl)
{
    func_02198318(mmdl, MMDL_DIR_RIGHT, 32, MMDL_DRAWSTA_WALK_32F);
    return 1;
}

u32 func_021983C0(Mmdl *mmdl)
{
    func_02198318(mmdl, MMDL_DIR_UP, 16, MMDL_DRAWSTA_WALK_16F);
    return 1;
}

u32 func_021983D0(Mmdl *mmdl)
{
    func_02198318(mmdl, MMDL_DIR_DOWN, 16, MMDL_DRAWSTA_WALK_16F);
    return 1;
}

u32 func_021983E0(Mmdl *mmdl)
{
    func_02198318(mmdl, MMDL_DIR_LEFT, 16, MMDL_DRAWSTA_WALK_16F);
    return 1;
}

u32 func_021983F0(Mmdl *mmdl)
{
    func_02198318(mmdl, MMDL_DIR_RIGHT, 16, MMDL_DRAWSTA_WALK_16F);
    return 1;
}

u32 func_02198400(Mmdl *mmdl)
{
    func_02198318(mmdl, MMDL_DIR_UP, 8, MMDL_DRAWSTA_WALK_8F);
    return 1;
}

u32 func_02198410(Mmdl *mmdl)
{
    func_02198318(mmdl, MMDL_DIR_DOWN, 8, MMDL_DRAWSTA_WALK_8F);
    return 1;
}

u32 func_02198420(Mmdl *mmdl)
{
    func_02198318(mmdl, MMDL_DIR_LEFT, 8, MMDL_DRAWSTA_WALK_8F);
    return 1;
}

u32 func_02198430(Mmdl *mmdl)
{
    func_02198318(mmdl, MMDL_DIR_RIGHT, 8, MMDL_DRAWSTA_WALK_8F);
    return 1;
}

u32 func_02198440(Mmdl *mmdl)
{
    func_02198318(mmdl, MMDL_DIR_UP, 4, MMDL_DRAWSTA_WALK_4F);
    return 1;
}

u32 func_02198450(Mmdl *mmdl)
{
    func_02198318(mmdl, MMDL_DIR_DOWN, 4, MMDL_DRAWSTA_WALK_4F);
    return 1;
}

u32 func_02198460(Mmdl *mmdl)
{
    func_02198318(mmdl, MMDL_DIR_LEFT, 4, MMDL_DRAWSTA_WALK_4F);
    return 1;
}

u32 func_02198470(Mmdl *mmdl)
{
    func_02198318(mmdl, MMDL_DIR_RIGHT, 4, MMDL_DRAWSTA_WALK_4F);
    return 1;
}

u32 func_02198480(Mmdl *mmdl)
{
    func_02198318(mmdl, MMDL_DIR_UP, 2, MMDL_DRAWSTA_WALK_2F);
    return 1;
}

u32 func_02198490(Mmdl *mmdl)
{
    func_02198318(mmdl, MMDL_DIR_DOWN, 2, MMDL_DRAWSTA_WALK_2F);
    return 1;
}

u32 func_021984A0(Mmdl *mmdl)
{
    func_02198318(mmdl, MMDL_DIR_LEFT, 2, MMDL_DRAWSTA_WALK_2F);
    return 1;
}

u32 func_021984B0(Mmdl *mmdl)
{
    func_02198318(mmdl, MMDL_DIR_RIGHT, 2, MMDL_DRAWSTA_WALK_2F);
    return 1;
}

void func_021984C0(Mmdl *mmdl, u32 dir, u32 speed, u32 frames, u16 drawStatus, s16 heightTable, u16 heightStep, u32 se)
{
    AcmdJumpWork *work;
    work = func_0216D6BC(mmdl, sizeof(AcmdJumpWork));
    work->dir = dir;
    work->speed = speed;
    work->framesLeft = frames;
    work->drawStatus = drawStatus;
    work->heightTable = heightTable;
    work->heightStep = heightStep;
    if (speed == 0) {
        func_02163F10(mmdl);
    } else {
        func_02163E7C(mmdl, (u16)dir);
    }
    func_0216D568(mmdl, MMDL_MOVEBIT_JUMP_START | MMDL_MOVEBIT_MOVE_START);
    func_0216D60C(mmdl, dir);
    func_0216D674(mmdl, drawStatus);
    func_0216D7CC(mmdl);
    if (se != 0) {
        func_020061E4(se);
    }
}

void func_0219852C(Mmdl *mmdl, u32 dir, u32 speed, u32 frames, u16 drawStatus, s16 heightTable, u16 heightStep)
{
    func_021984C0(mmdl, dir, speed, frames, drawStatus, heightTable, heightStep, SE_JUMP);
}

int func_02198550(Mmdl *mmdl)
{
    AcmdJumpWork *work;
    work = func_0216D6D4(mmdl);
    if (work->speed != 0) {
        func_02163FC0(mmdl, work->dir, work->speed);
        func_02164010(mmdl);
        if (work->progress >= ACMD_GRID_FIXED) {
            work->progress = 0;
            func_02163E7C(mmdl, work->dir);
            func_0216D568(mmdl, MMDL_MOVEBIT_MOVE_START);
        }
        work->progress += (work->speed < 0) ? -work->speed : work->speed;
    }
    work->height += work->heightStep;
    if (work->height > 0xF00) {
        work->height = 0xF00;
    }
    {
        MmdlVec offset;
        u16 index;
        int table;

        index = work->height / 256;
        table = work->heightTable;
        offset.x = 0;
        offset.y = d_021DDBD4[table][index];
        offset.z = 0;
        func_0216D8C0(mmdl, &offset);
    }
    work->framesLeft = work->framesLeft - 1;
    if (work->framesLeft > 0) {
        return 0;
    }
    {
        MmdlVec offset = { 0, 0, 0 };
        func_0216D8C0(mmdl, &offset);
    }
    func_0216D568(mmdl, MMDL_MOVEBIT_JUMP_END | MMDL_MOVEBIT_MOVE_END | MMDL_MOVEBIT_ACMD_END);
    func_02163F10(mmdl);
    func_0216D674(mmdl, 0);
    func_0216D7CC(mmdl);
    func_020061E4(SE_LAND);
    return 1;
}

int func_0219862C(Mmdl *mmdl)
{
    func_0219852C(mmdl, MMDL_DIR_UP, 0, 16, MMDL_DRAWSTA_WALK_16F, 1, 0x100);
    return 1;
}

int func_02198650(Mmdl *mmdl)
{
    func_0219852C(mmdl, MMDL_DIR_DOWN, 0, 16, MMDL_DRAWSTA_WALK_16F, 1, 0x100);
    return 1;
}

int func_02198674(Mmdl *mmdl)
{
    func_0219852C(mmdl, MMDL_DIR_LEFT, 0, 16, MMDL_DRAWSTA_WALK_16F, 1, 0x100);
    return 1;
}

int func_02198694(Mmdl *mmdl)
{
    func_0219852C(mmdl, MMDL_DIR_RIGHT, 0, 16, MMDL_DRAWSTA_WALK_16F, 1, 0x100);
    return 1;
}

int func_021986B8(Mmdl *mmdl)
{
    func_0219852C(mmdl, MMDL_DIR_UP, 0, 8, MMDL_DRAWSTA_WALK_8F, 1, 0x200);
    return 1;
}

int func_021986D8(Mmdl *mmdl)
{
    func_0219852C(mmdl, MMDL_DIR_DOWN, 0, 8, MMDL_DRAWSTA_WALK_8F, 1, 0x200);
    return 1;
}

int func_021986F8(Mmdl *mmdl)
{
    func_0219852C(mmdl, MMDL_DIR_LEFT, 0, 8, MMDL_DRAWSTA_WALK_8F, 1, 0x200);
    return 1;
}

int func_02198718(Mmdl *mmdl)
{
    func_0219852C(mmdl, MMDL_DIR_RIGHT, 0, 8, MMDL_DRAWSTA_WALK_8F, 1, 0x200);
    return 1;
}

int func_02198738(Mmdl *mmdl)
{
    func_0219852C(mmdl, MMDL_DIR_UP, ACMD_GRID_SPEED(8), 8, MMDL_DRAWSTA_WALK_8F, 0, 0x200);
    return 1;
}

int func_02198758(Mmdl *mmdl)
{
    func_0219852C(mmdl, MMDL_DIR_DOWN, ACMD_GRID_SPEED(8), 8, MMDL_DRAWSTA_WALK_8F, 0, 0x200);
    return 1;
}

int func_0219877C(Mmdl *mmdl)
{
    func_0219852C(mmdl, MMDL_DIR_LEFT, ACMD_GRID_SPEED(8), 8, MMDL_DRAWSTA_WALK_8F, 0, 0x200);
    return 1;
}

int func_021987A0(Mmdl *mmdl)
{
    func_0219852C(mmdl, MMDL_DIR_RIGHT, ACMD_GRID_SPEED(8), 8, MMDL_DRAWSTA_WALK_8F, 0, 0x200);
    return 1;
}

int func_021987C0(Mmdl *mmdl)
{
    func_0219852C(mmdl, MMDL_DIR_UP, 2 * ACMD_GRID_SPEED(16), 16, MMDL_DRAWSTA_WALK_8F, 0, 0x100);
    return 1;
}

int func_021987E0(Mmdl *mmdl)
{
    func_0219852C(mmdl, MMDL_DIR_DOWN, 2 * ACMD_GRID_SPEED(16), 16, MMDL_DRAWSTA_WALK_8F, 0, 0x100);
    return 1;
}

int func_02198804(Mmdl *mmdl)
{
    func_0219852C(mmdl, MMDL_DIR_LEFT, 2 * ACMD_GRID_SPEED(16), 16, MMDL_DRAWSTA_WALK_8F, 0, 0x100);
    return 1;
}

int func_02198824(Mmdl *mmdl)
{
    func_0219852C(mmdl, MMDL_DIR_RIGHT, 2 * ACMD_GRID_SPEED(16), 16, MMDL_DRAWSTA_WALK_8F, 0, 0x100);
    return 1;
}

int func_02198848(Mmdl *mmdl)
{
    func_0219852C(mmdl, MMDL_DIR_LEFT, ACMD_GRID_SPEED(16), 16, MMDL_DRAWSTA_WALK_16F, 0, 0xF0);
    return 1;
}

int func_02198868(Mmdl *mmdl)
{
    func_0219852C(mmdl, MMDL_DIR_RIGHT, ACMD_GRID_SPEED(16), 16, MMDL_DRAWSTA_WALK_16F, 0, 0xF0);
    return 1;
}

int func_02198888(Mmdl *mmdl)
{
    func_0219852C(mmdl, MMDL_DIR_LEFT, 0x4000, 12, MMDL_DRAWSTA_WALK_8F, 0, 0x140);
    return 1;
}

int func_021988AC(Mmdl *mmdl)
{
    func_0219852C(mmdl, MMDL_DIR_RIGHT, 0x4000, 12, MMDL_DRAWSTA_WALK_8F, 0, 0x140);
    return 1;
}

int func_021988D0(Mmdl *mmdl)
{
    func_021984C0(mmdl, MMDL_DIR_UP, 0x2000, 24, MMDL_DRAWSTA_WALK_8F, 0, 0xA0, 0);
    return 1;
}

int func_021988F4(Mmdl *mmdl)
{
    func_021984C0(mmdl, MMDL_DIR_DOWN, 0x2000, 24, MMDL_DRAWSTA_WALK_8F, 0, 0xA0, 0);
    return 1;
}

int func_02198918(Mmdl *mmdl)
{
    func_021984C0(mmdl, MMDL_DIR_LEFT, 0x2000, 24, MMDL_DRAWSTA_WALK_8F, 0, 0xA0, 0);
    return 1;
}

int func_0219893C(Mmdl *mmdl)
{
    func_021984C0(mmdl, MMDL_DIR_RIGHT, 0x2000, 24, MMDL_DRAWSTA_WALK_8F, 0, 0xA0, 0);
    return 1;
}

int func_02198960(Mmdl *mmdl, u32 frames)
{
    ((AcmdWaitWork *)func_0216D6BC(mmdl, sizeof(AcmdWaitWork)))->framesLeft = frames;
    return func_0216D7CC(mmdl);
}

int func_02198978(Mmdl *mmdl)
{
    AcmdWaitWork *work;
    work = (AcmdWaitWork *)func_0216D6D4(mmdl);
    if (work->framesLeft != 0) {
        work->framesLeft -= 1;
        return 0;
    }
    func_0216D7CC(mmdl);
    return 1;
}

u32 func_02198998(Mmdl *mmdl)
{
    func_02198960(mmdl, 1);
    return 1;
}

u32 func_021989A4(Mmdl *mmdl)
{
    func_02198960(mmdl, 2);
    return 1;
}

u32 func_021989B0(Mmdl *mmdl)
{
    func_02198960(mmdl, 4);
    return 1;
}

u32 func_021989BC(Mmdl *mmdl)
{
    func_02198960(mmdl, 8);
    return 1;
}

u32 func_021989C8(Mmdl *mmdl)
{
    func_02198960(mmdl, 15);
    return 1;
}

u32 func_021989D4(Mmdl *mmdl)
{
    func_02198960(mmdl, 16);
    return 1;
}

u32 func_021989E0(Mmdl *mmdl)
{
    func_02198960(mmdl, 32);
    return 1;
}

int func_021989EC(Mmdl *mmdl)
{
    ((AcmdRiseWork *)func_0216D6BC(mmdl, sizeof(AcmdRiseWork)))->step = ACMD_GRID_FIXED;
    func_0216D674(mmdl, 0);
    func_0216D7CC(mmdl);
    return 1;
}

int func_02198A10(Mmdl *mmdl)
{
    AcmdRiseWork *work;
    work = func_0216D6D4(mmdl);
    work->height = work->height + work->step;
    {
        MmdlVec offset = { 0, 0, 0 };
        offset.y = work->height;
        func_0216D8C0(mmdl, &offset);
    }
    if (work->height / 0x8000 < 0x28) {
        return 0;
    }
    func_0216D7CC(mmdl);
    return 1;
}

int func_02198A58(Mmdl *mmdl)
{
    AcmdRiseWork *work;
    work = func_0216D6BC(mmdl, sizeof(AcmdRiseWork));
    work->height = 0x140000;
    work->step = -ACMD_GRID_FIXED;
    func_020061E4(SE_FALL);
    func_0216D674(mmdl, 0);
    func_0216D7CC(mmdl);
    return 1;
}

int func_02198A8C(Mmdl *mmdl)
{
    AcmdRiseWork *work;
    work = func_0216D6D4(mmdl);
    work->height = work->height + work->step;
    if (work->height < 0) {
        work->height = 0;
    }
    {
        MmdlVec offset = { 0, 0, 0 };
        offset.y = work->height;
        func_0216D8C0(mmdl, &offset);
    }
    if (work->height > 0) {
        return 0;
    }
    func_0216D7CC(mmdl);
    return 1;
}

int func_02198AD4(Mmdl *mmdl)
{
    func_0216D548(mmdl, MMDL_STABIT_VANISH);
    func_0216D7CC(mmdl);
    return 1;
}

int func_02198AE8(Mmdl *mmdl)
{
    func_0216D550(mmdl, MMDL_STABIT_VANISH);
    func_0216D7CC(mmdl);
    return 1;
}

int func_02198AFC(Mmdl *mmdl)
{
    func_0216D548(mmdl, MMDL_STABIT_PAUSE_DIR);
    func_0216D7CC(mmdl);
    return 1;
}

int func_02198B10(Mmdl *mmdl)
{
    func_0216D550(mmdl, MMDL_STABIT_PAUSE_DIR);
    func_0216D7CC(mmdl);
    return 1;
}

int func_02198B24(Mmdl *mmdl)
{
    func_0216D548(mmdl, MMDL_STABIT_PAUSE_ANIME);
    func_0216D7CC(mmdl);
    return 1;
}

int func_02198B38(Mmdl *mmdl)
{
    func_0216D550(mmdl, MMDL_STABIT_PAUSE_ANIME);
    func_0216D7CC(mmdl);
    return 1;
}

void func_02198B4C(Mmdl *mmdl, u32 markType, u32 reserved)
{
    AcmdMarkWork *work;
    work = func_0216D6BC(mmdl, sizeof(AcmdMarkWork));
    work->markType = markType;
    work->effect = func_021BB528(func_02188CD0(func_0216D534(func_0216D67C(mmdl))), mmdl, markType, 1);
    func_0216D7CC(mmdl);
}

int func_02198B80(Mmdl *mmdl)
{
    AcmdMarkWork *work;
    work = func_0216D6D4(mmdl);
    if (func_021BB5C8(work->effect) == 1) {
        func_021AC154(work->effect);
        func_0216D7CC(mmdl);
        return 1;
    }
    return 0;
}

u32 func_02198BA8(Mmdl *mmdl)
{
    func_02198B4C(mmdl, 0, 0);
    return 0;
}

u32 func_02198BB8(Mmdl *mmdl)
{
    func_02198B4C(mmdl, 0, 0);
    return 0;
}

u32 func_02198BC8(Mmdl *mmdl)
{
    func_02198B4C(mmdl, 0, 0);
    return 0;
}

u32 func_02198BD8(Mmdl *mmdl)
{
    func_02198B4C(mmdl, 1, 0);
    return 0;
}

u32 func_02198BE8(Mmdl *mmdl)
{
    func_02198B4C(mmdl, 2, 0);
    return 0;
}

u32 func_02198BF8(Mmdl *mmdl)
{
    func_02198B4C(mmdl, 3, 0);
    return 0;
}

void func_02198C08(Mmdl *mmdl, u32 dir, u32 frames, u16 drawStatus)
{
    AcmdWalkTableWork *work;
    work = func_0216D6BC(mmdl, sizeof(AcmdWalkTableWork));
    work->dir = dir;
    work->drawStatus = drawStatus;
    work->frames = frames;
    func_02163E7C(mmdl, (dir << 16) >> 16);
    func_0216D60C(mmdl, dir);
    func_0216D674(mmdl, drawStatus);
    func_0216D568(mmdl, MMDL_MOVEBIT_MOVE_START);
    func_0216D7CC(mmdl);
}

int func_02198C4C(Mmdl *mmdl, const u32 *stepTable)
{
    AcmdWalkTableWork *work;
    work = func_0216D6D4(mmdl);
    func_02163FC0(mmdl, work->dir, stepTable[work->frameIndex]);
    func_02164010(mmdl);
    work->frameIndex = work->frameIndex + 1;
    if (work->frameIndex < work->frames) {
        return 0;
    }
    func_0216D568(mmdl, MMDL_MOVEBIT_MOVE_END | MMDL_MOVEBIT_ACMD_END);
    func_02163F10(mmdl);
    func_0216D674(mmdl, 0);
    func_0216D7CC(mmdl);
    return 1;
}

u32 func_02198CA4(Mmdl *mmdl)
{
    func_02198C08(mmdl, MMDL_DIR_UP, 6, MMDL_DRAWSTA_WALK_6F);
    return 1;
}

u32 func_02198CB4(Mmdl *mmdl)
{
    func_02198C08(mmdl, MMDL_DIR_DOWN, 6, MMDL_DRAWSTA_WALK_6F);
    return 1;
}

u32 func_02198CC4(Mmdl *mmdl)
{
    func_02198C08(mmdl, MMDL_DIR_LEFT, 6, MMDL_DRAWSTA_WALK_6F);
    return 1;
}

u32 func_02198CD4(Mmdl *mmdl)
{
    func_02198C08(mmdl, MMDL_DIR_RIGHT, 6, MMDL_DRAWSTA_WALK_6F);
    return 1;
}

u32 func_02198CE4(Mmdl *mmdl)
{
    func_02198C08(mmdl, MMDL_DIR_UP, 6, MMDL_DRAWSTA_DASH_6F);
    return 1;
}

u32 func_02198CF4(Mmdl *mmdl)
{
    func_02198C08(mmdl, MMDL_DIR_DOWN, 6, MMDL_DRAWSTA_DASH_6F);
    return 1;
}

u32 func_02198D04(Mmdl *mmdl)
{
    func_02198C08(mmdl, MMDL_DIR_LEFT, 6, MMDL_DRAWSTA_DASH_6F);
    return 1;
}

u32 func_02198D14(Mmdl *mmdl)
{
    func_02198C08(mmdl, MMDL_DIR_RIGHT, 6, MMDL_DRAWSTA_DASH_6F);
    return 1;
}

/* Step of the 6 frame walks: the speed of each frame comes from d_021D4A68. */
int func_02198D24(Mmdl *mmdl)
{
    if (func_02198C4C(mmdl, d_021D4A68) == 1) {
        return 1;
    }
    return 0;
}

/* Walks of 3 frames (step table d_021D4A44), 7 frames (d_021D4A80) and 12 frames (d_021D4A9C). */
u32 func_02198D3C(Mmdl *mmdl)
{
    func_02198C08(mmdl, MMDL_DIR_UP, 3, MMDL_DRAWSTA_WALK_3F);
    return 1;
}

u32 func_02198D4C(Mmdl *mmdl)
{
    func_02198C08(mmdl, MMDL_DIR_DOWN, 3, MMDL_DRAWSTA_WALK_3F);
    return 1;
}

u32 func_02198D5C(Mmdl *mmdl)
{
    func_02198C08(mmdl, MMDL_DIR_LEFT, 3, MMDL_DRAWSTA_WALK_3F);
    return 1;
}

u32 func_02198D6C(Mmdl *mmdl)
{
    func_02198C08(mmdl, MMDL_DIR_RIGHT, 3, MMDL_DRAWSTA_WALK_3F);
    return 1;
}

int func_02198D7C(Mmdl *mmdl)
{
    if (func_02198C4C(mmdl, d_021D4A44) == 1) {
        return 1;
    }
    return 0;
}

u32 func_02198D94(Mmdl *mmdl)
{
    func_02198C08(mmdl, MMDL_DIR_UP, 7, MMDL_DRAWSTA_WALK_7F);
    return 1;
}

u32 func_02198DA4(Mmdl *mmdl)
{
    func_02198C08(mmdl, MMDL_DIR_DOWN, 7, MMDL_DRAWSTA_WALK_7F);
    return 1;
}

u32 func_02198DB4(Mmdl *mmdl)
{
    func_02198C08(mmdl, MMDL_DIR_LEFT, 7, MMDL_DRAWSTA_WALK_7F);
    return 1;
}

u32 func_02198DC4(Mmdl *mmdl)
{
    func_02198C08(mmdl, MMDL_DIR_RIGHT, 7, MMDL_DRAWSTA_WALK_7F);
    return 1;
}

int func_02198DD4(Mmdl *mmdl)
{
    if (func_02198C4C(mmdl, d_021D4A80) == 1) {
        return 1;
    }
    return 0;
}

u32 func_02198DEC(Mmdl *mmdl)
{
    func_02198C08(mmdl, MMDL_DIR_UP, 12, MMDL_DRAWSTA_WALK_12F);
    return 1;
}

u32 func_02198DFC(Mmdl *mmdl)
{
    func_02198C08(mmdl, MMDL_DIR_DOWN, 12, MMDL_DRAWSTA_WALK_12F);
    return 1;
}

u32 func_02198E0C(Mmdl *mmdl)
{
    func_02198C08(mmdl, MMDL_DIR_LEFT, 12, MMDL_DRAWSTA_WALK_12F);
    return 1;
}

u32 func_02198E1C(Mmdl *mmdl)
{
    func_02198C08(mmdl, MMDL_DIR_RIGHT, 12, MMDL_DRAWSTA_WALK_12F);
    return 1;
}

int func_02198E2C(Mmdl *mmdl)
{
    if (func_02198C4C(mmdl, d_021D4A9C) == 1) {
        return 1;
    }
    return 0;
}

/* Starts a draw status (dash animation) and goes on at the next frame. */
int func_02198E44(Mmdl *mmdl)
{
    func_0216D6BC(mmdl, sizeof(AcmdAnimeWork));
    func_0216D674(mmdl, MMDL_DRAWSTA_DASH_4F);
    func_0216D7CC(mmdl);
    return 0;
}

int func_02198E60(Mmdl *mmdl)
{
    func_0216D6BC(mmdl, sizeof(AcmdAnimeWork));
    func_0216D674(mmdl, MMDL_DRAWSTA_DASH_6F);
    func_0216D7CC(mmdl);
    return 0;
}

int func_02198E7C(Mmdl *mmdl)
{
    func_0216D6BC(mmdl, sizeof(AcmdAnimeWork));
    func_0216D674(mmdl, MMDL_DRAWSTA_DASH_2F);
    func_0216D7CC(mmdl);
    return 0;
}

int func_02198E98(Mmdl *mmdl)
{
    func_020061E4(SE_DASH_START);
    return func_02198E44(mmdl);
}

int func_02198EB0(Mmdl *mmdl)
{
    func_020061E4(SE_DASH_START);
    return func_02198E60(mmdl);
}

/* Waits for the end of the draw animation, then stops the draw status. */
int func_02198EC8(Mmdl *mmdl)
{
    u32 animeId;
    u16 animeFlag;

    func_0216D6D4(mmdl);
    animeId = func_0216D7A8(mmdl, 0);
    if (animeId != 0xFFFF) {
        if (func_020508EC(func_0219C9DC(func_0216D520(func_0216D67C(mmdl))), (u16)animeId, &animeFlag) == 1) {
            func_0216D674(mmdl, MMDL_DRAWSTA_STOP);
            func_0216D7CC(mmdl);
            return 1;
        }
    }
    return 0;
}

/* Waits for the end of the draw animation. */
int func_02198F20(Mmdl *mmdl)
{
    u32 animeId;
    u16 animeFlag;

    func_0216D6D4(mmdl);
    animeId = func_0216D7A8(mmdl, 0);
    if (animeId != 0xFFFF) {
        if (func_020508EC(func_0219C9DC(func_0216D520(func_0216D67C(mmdl))), (u16)animeId, &animeFlag) == 1) {
            func_0216D7CC(mmdl);
            return 1;
        }
    }
    return 0;
}

/* Leaves the hide effect: a hop along height table 0. */
int func_02198F68(Mmdl *mmdl)
{
    u32 effect;

    func_0216D6BC(mmdl, sizeof(AcmdHideWork));
    effect = func_0219BF48(mmdl);
    if (effect != 0) {
        func_021D04A4(effect);
    }
    {
        MmdlVec offset = { 0, 0, 0 };
        func_0216D8C0(mmdl, &offset);
    }
    func_0216D568(mmdl, MMDL_MOVEBIT_JUMP_START | MMDL_MOVEBIT_MOVE_START);
    func_0216D570(mmdl, MMDL_MOVEBIT_SHOAL_SET);
    func_0216D7CC(mmdl);
    return 0;
}

int func_02198FB0(Mmdl *mmdl)
{
    AcmdHideWork *work;
    u32 effect;

    work = func_0216D6D4(mmdl);
    {
        MmdlVec offset = { 0, 0, 0 };
        offset.y = d_021DDBD4[0][work->heightIndex];
        func_0216D8C0(mmdl, &offset);
        effect = func_0219BF48(mmdl);
        if (effect != 0) {
            if (func_021D04C4(effect) == 1) {
                func_021AC154(effect);
                func_0219BF3C(mmdl, 0);
            }
        }
        work->heightIndex = work->heightIndex + 2;
        if (work->heightIndex < 16) {
            return 0;
        }
        offset.y = 0;
        func_0216D8C0(mmdl, &offset);
    }
    func_0216D568(mmdl, MMDL_MOVEBIT_JUMP_END | MMDL_MOVEBIT_MOVE_END | MMDL_MOVEBIT_ACMD_END);
    func_0219BF54(mmdl);
    func_0216D7CC(mmdl);
    return 1;
}

/* Walks in place with a draw status for the given number of frames. */
void func_02199034(Mmdl *mmdl, u16 drawStatus, u32 frames)
{
    ((AcmdStayWork *)func_0216D6BC(mmdl, sizeof(AcmdStayWork)))->frames = frames;
    func_0216D674(mmdl, drawStatus);
}

int func_02199050(Mmdl *mmdl)
{
    AcmdStayWork *work;

    work = func_0216D6D4(mmdl);
    work->elapsed++;
    if (work->elapsed >= work->frames) {
        func_0216D7CC(mmdl);
    }
    return 0;
}

int func_02199070(Mmdl *mmdl)
{
    func_02199034(mmdl, MMDL_DRAWSTA_WALK_32F, 40);
    func_0216D7CC(mmdl);
    return 0;
}

int func_02199088(Mmdl *mmdl)
{
    func_02199034(mmdl, MMDL_DRAWSTA_WALK_16F, 40);
    func_0216D7CC(mmdl);
    return 0;
}

int func_021990A0(Mmdl *mmdl)
{
    func_02199034(mmdl, MMDL_DRAWSTA_STOP, 12);
    func_0216D7CC(mmdl);
    return 0;
}

/* Starts a bounce in place: the height of each frame comes from d_021D4C1C. */
int func_021990B8(Mmdl *mmdl)
{
    func_0216D6BC(mmdl, sizeof(AcmdCounterWork));
    func_0216D674(mmdl, MMDL_DRAWSTA_WALK_32F);
    func_0216D7CC(mmdl);
    return 1;
}

int func_021990D4(Mmdl *mmdl)
{
    MmdlVec offset = { 0, 0, 0 };
    AcmdBounceTable heights;
    AcmdCounterWork *work;
    int index;

    heights = d_021D4C1C;
    work = func_0216D6D4(mmdl);
    index = work->count;
    if (index >= 10) {
        index = 9;
    }
    offset.y = heights.height[index];
    func_0216D8C0(mmdl, &offset);
    work->count = work->count + 1;
    if (work->count >= 20) {
        func_0216D7CC(mmdl);
    }
    return 0;
}

/* Starts a step of the given frames along the vector, facing dispDir while moving to moveDir. */
void func_0219912C(Mmdl *mmdl, const MmdlVec *step, u32 dispDir, u32 moveDir, u32 frames, u8 drawStatus)
{
    AcmdStepWork *work;

    work = func_0216D6BC(mmdl, sizeof(AcmdStepWork));
    work->framesLeft = frames;
    work->step = *step;
    func_0216D5E0(mmdl, (u16)dispDir);
    func_0216D600(mmdl, (u16)moveDir);
    func_0216D674(mmdl, drawStatus);
    func_0216DA70(mmdl);
    func_0216D80C(mmdl, func_0216D83C(mmdl));
    func_0216D818(mmdl, func_0216D854(mmdl));
    func_0216D824(mmdl, func_0216D86C(mmdl));
    if (step->x < 0) {
        func_0216D848(mmdl, -1);
    } else if (step->x > 0) {
        func_0216D848(mmdl, 1);
    }
    if (step->y < 0) {
        func_0216D860(mmdl, -1);
    } else if (step->y > 0) {
        func_0216D860(mmdl, 1);
    }
    if (step->z < 0) {
        func_0216D87C(mmdl, -1);
    } else if (step->z > 0) {
        func_0216D87C(mmdl, 1);
    }
    func_0216D7CC(mmdl);
}

int func_021991F0(Mmdl *mmdl)
{
    AcmdStepWork *work;

    work = func_0216D6D4(mmdl);
    func_02163F8C(mmdl, &work->step);
    work->framesLeft = work->framesLeft - 1;
    if (work->framesLeft > 0) {
        return 0;
    }
    func_0216D568(mmdl, MMDL_MOVEBIT_MOVE_END | MMDL_MOVEBIT_ACMD_END);
    func_02163F10(mmdl);
    func_0216D674(mmdl, MMDL_DRAWSTA_STOP);
    func_0216D7CC(mmdl);
    return 1;
}

/* Steps of 8, 4 and 2 frames, then 4 frame dash steps, along one vector: the model faces dispDir while it moves to moveDir. */
int func_02199234(Mmdl *mmdl)
{
    MmdlVec step = d_021D4B44;
    func_0219912C(mmdl, &step, MMDL_DIR_LEFT, MMDL_DIR_UP, 8, MMDL_DRAWSTA_WALK_8F);
    return 1;
}

int func_02199268(Mmdl *mmdl)
{
    MmdlVec step = d_021D4204;
    func_0219912C(mmdl, &step, MMDL_DIR_RIGHT, MMDL_DIR_DOWN, 8, MMDL_DRAWSTA_WALK_8F);
    return 1;
}

int func_02199298(Mmdl *mmdl)
{
    MmdlVec step = d_021D4C04;
    func_0219912C(mmdl, &step, MMDL_DIR_DOWN, MMDL_DIR_LEFT, 8, MMDL_DRAWSTA_WALK_8F);
    return 1;
}

int func_021992CC(Mmdl *mmdl)
{
    MmdlVec step = d_021D41E0;
    func_0219912C(mmdl, &step, MMDL_DIR_UP, MMDL_DIR_RIGHT, 8, MMDL_DRAWSTA_WALK_8F);
    return 1;
}

int func_021992FC(Mmdl *mmdl)
{
    MmdlVec step = d_021D4210;
    func_0219912C(mmdl, &step, MMDL_DIR_RIGHT, MMDL_DIR_UP, 8, MMDL_DRAWSTA_WALK_8F);
    return 1;
}

int func_0219932C(Mmdl *mmdl)
{
    MmdlVec step = d_021D4C10;
    func_0219912C(mmdl, &step, MMDL_DIR_LEFT, MMDL_DIR_DOWN, 8, MMDL_DRAWSTA_WALK_8F);
    return 1;
}

int func_02199360(Mmdl *mmdl)
{
    MmdlVec step = d_021D4648;
    func_0219912C(mmdl, &step, MMDL_DIR_UP, MMDL_DIR_LEFT, 8, MMDL_DRAWSTA_WALK_8F);
    return 1;
}

int func_02199394(Mmdl *mmdl)
{
    MmdlVec step = d_021D4BF8;
    func_0219912C(mmdl, &step, MMDL_DIR_DOWN, MMDL_DIR_LEFT, 8, MMDL_DRAWSTA_WALK_8F);
    return 1;
}

int func_021993C8(Mmdl *mmdl)
{
    MmdlVec step = d_021D4BEC;
    func_0219912C(mmdl, &step, MMDL_DIR_DOWN, MMDL_DIR_UP, 8, MMDL_DRAWSTA_WALK_8F);
    return 1;
}

int func_021993FC(Mmdl *mmdl)
{
    MmdlVec step = d_021D4BE0;
    func_0219912C(mmdl, &step, MMDL_DIR_UP, MMDL_DIR_DOWN, 8, MMDL_DRAWSTA_WALK_8F);
    return 1;
}

int func_02199430(Mmdl *mmdl)
{
    MmdlVec step = d_021D4BD4;
    func_0219912C(mmdl, &step, MMDL_DIR_RIGHT, MMDL_DIR_LEFT, 8, MMDL_DRAWSTA_WALK_8F);
    return 1;
}

int func_02199460(Mmdl *mmdl)
{
    MmdlVec step = d_021D4BC8;
    func_0219912C(mmdl, &step, MMDL_DIR_LEFT, MMDL_DIR_RIGHT, 8, MMDL_DRAWSTA_WALK_8F);
    return 1;
}

int func_02199490(Mmdl *mmdl)
{
    MmdlVec step = d_021D4BBC;
    func_0219912C(mmdl, &step, MMDL_DIR_DOWN, MMDL_DIR_UP, 4, MMDL_DRAWSTA_WALK_4F);
    return 1;
}

int func_021994C0(Mmdl *mmdl)
{
    MmdlVec step = d_021D4BB0;
    func_0219912C(mmdl, &step, MMDL_DIR_UP, MMDL_DIR_DOWN, 4, MMDL_DRAWSTA_WALK_4F);
    return 1;
}

int func_021994F0(Mmdl *mmdl)
{
    MmdlVec step = d_021D4BA4;
    func_0219912C(mmdl, &step, MMDL_DIR_RIGHT, MMDL_DIR_LEFT, 4, MMDL_DRAWSTA_WALK_4F);
    return 1;
}

int func_02199520(Mmdl *mmdl)
{
    MmdlVec step = d_021D4B98;
    func_0219912C(mmdl, &step, MMDL_DIR_LEFT, MMDL_DIR_RIGHT, 4, MMDL_DRAWSTA_WALK_4F);
    return 1;
}

int func_02199550(Mmdl *mmdl)
{
    MmdlVec step = d_021D4B8C;
    func_0219912C(mmdl, &step, MMDL_DIR_DOWN, MMDL_DIR_UP, 2, MMDL_DRAWSTA_WALK_2F);
    return 1;
}

int func_02199584(Mmdl *mmdl)
{
    MmdlVec step = d_021D4B80;
    func_0219912C(mmdl, &step, MMDL_DIR_UP, MMDL_DIR_DOWN, 2, MMDL_DRAWSTA_WALK_2F);
    return 1;
}

int func_021995B8(Mmdl *mmdl)
{
    MmdlVec step = d_021D4B74;
    func_0219912C(mmdl, &step, MMDL_DIR_RIGHT, MMDL_DIR_LEFT, 2, MMDL_DRAWSTA_WALK_2F);
    return 1;
}

int func_021995E8(Mmdl *mmdl)
{
    MmdlVec step = d_021D4B68;
    func_0219912C(mmdl, &step, MMDL_DIR_LEFT, MMDL_DIR_RIGHT, 2, MMDL_DRAWSTA_WALK_2F);
    return 1;
}

int func_02199618(Mmdl *mmdl)
{
    MmdlVec step = d_021D4B5C;
    func_0219912C(mmdl, &step, MMDL_DIR_LEFT, MMDL_DIR_UP, 4, MMDL_DRAWSTA_DASH_4F);
    return 1;
}

int func_0219964C(Mmdl *mmdl)
{
    MmdlVec step = d_021D4B50;
    func_0219912C(mmdl, &step, MMDL_DIR_RIGHT, MMDL_DIR_DOWN, 4, MMDL_DRAWSTA_DASH_4F);
    return 1;
}

int func_02199680(Mmdl *mmdl)
{
    MmdlVec step = d_021D45E8;
    func_0219912C(mmdl, &step, MMDL_DIR_DOWN, MMDL_DIR_LEFT, 4, MMDL_DRAWSTA_DASH_4F);
    return 1;
}

int func_021996B4(Mmdl *mmdl)
{
    MmdlVec step = d_021D4B38;
    func_0219912C(mmdl, &step, MMDL_DIR_UP, MMDL_DIR_RIGHT, 4, MMDL_DRAWSTA_DASH_4F);
    return 1;
}

int func_021996E8(Mmdl *mmdl)
{
    MmdlVec step = d_021D4B2C;
    func_0219912C(mmdl, &step, MMDL_DIR_RIGHT, MMDL_DIR_UP, 4, MMDL_DRAWSTA_DASH_4F);
    return 1;
}

int func_0219971C(Mmdl *mmdl)
{
    MmdlVec step = d_021D4B20;
    func_0219912C(mmdl, &step, MMDL_DIR_LEFT, MMDL_DIR_DOWN, 4, MMDL_DRAWSTA_DASH_4F);
    return 1;
}

int func_02199750(Mmdl *mmdl)
{
    MmdlVec step = d_021D4B14;
    func_0219912C(mmdl, &step, MMDL_DIR_UP, MMDL_DIR_LEFT, 4, MMDL_DRAWSTA_DASH_4F);
    return 1;
}

int func_02199784(Mmdl *mmdl)
{
    MmdlVec step = d_021D4B08;
    func_0219912C(mmdl, &step, MMDL_DIR_DOWN, MMDL_DIR_LEFT, 4, MMDL_DRAWSTA_DASH_4F);
    return 1;
}

int func_021997B8(Mmdl *mmdl)
{
    MmdlVec step = d_021D4AFC;
    func_0219912C(mmdl, &step, MMDL_DIR_DOWN, MMDL_DIR_UP, 4, MMDL_DRAWSTA_DASH_4F);
    return 1;
}

int func_021997EC(Mmdl *mmdl)
{
    MmdlVec step = d_021D4AF0;
    func_0219912C(mmdl, &step, MMDL_DIR_UP, MMDL_DIR_DOWN, 4, MMDL_DRAWSTA_DASH_4F);
    return 1;
}

int func_02199820(Mmdl *mmdl)
{
    MmdlVec step = d_021D4AE4;
    func_0219912C(mmdl, &step, MMDL_DIR_RIGHT, MMDL_DIR_LEFT, 4, MMDL_DRAWSTA_DASH_4F);
    return 1;
}

int func_02199854(Mmdl *mmdl)
{
    MmdlVec step = d_021D4AD8;
    func_0219912C(mmdl, &step, MMDL_DIR_LEFT, MMDL_DIR_RIGHT, 4, MMDL_DRAWSTA_DASH_4F);
    return 1;
}

/* Starts a jump of the given frames that moves along moveAxis and rises along arcAxis (height table 1). */
void func_02199888(Mmdl *mmdl, int speed, u32 dispDir, u32 moveDir, u8 frames, u8 drawStatus, u8 moveAxis, u8 arcAxis, u8 negate)
{
    AcmdHopWork *work;
    int sign;

    sign = 1;
    work = func_0216D6BC(mmdl, sizeof(AcmdHopWork));
    work->frames = frames;
    work->speed = speed;
    work->moveAxis = moveAxis;
    work->arcAxis = arcAxis;
    work->negate = negate;
    work->angleStep = 0x1000 / work->frames;
    func_0216D5E0(mmdl, (u16)dispDir);
    func_0216D600(mmdl, (u16)moveDir);
    func_0216D674(mmdl, drawStatus);
    func_0216DA70(mmdl);
    func_0216D80C(mmdl, func_0216D83C(mmdl));
    func_0216D818(mmdl, func_0216D854(mmdl));
    func_0216D824(mmdl, func_0216D86C(mmdl));
    if (speed != 0) {
        switch (moveAxis) {
        case ACMD_AXIS_X:
            if (speed < 0)
                sign = -1;
            func_0216D848(mmdl, sign);
            break;
        case ACMD_AXIS_Y:
            if (speed < 0)
                sign = -1;
            func_0216D860(mmdl, sign * 2);
            break;
        case ACMD_AXIS_Z:
            if (speed < 0)
                sign = -1;
            func_0216D87C(mmdl, sign);
            break;
        }
    }
    func_0216D7CC(mmdl);
}

int func_02199970(Mmdl *mmdl)
{
    AcmdHopWork *work;
    MmdlVec pos;
    int speedAbs;
    int height;

    work = func_0216D6D4(mmdl);
    func_0216D88C(mmdl, &pos);
    switch (work->moveAxis) {
    case ACMD_AXIS_X:
        pos.x += work->speed;
        break;
    case ACMD_AXIS_Y:
        pos.y += work->speed;
        break;
    case ACMD_AXIS_Z:
        pos.z += work->speed;
        break;
    }
    func_0216D89C(mmdl, &pos);
    speedAbs = work->speed;
    if (speedAbs < 0)
        speedAbs = -speedAbs;
    work->progress += speedAbs;
    work->angle += work->angleStep;
    if (work->angle > 0xF00)
        work->angle = 0xF00;
    {
        MmdlVec offset = { 0, 0, 0 };
        height = d_021DDBD4[1][(u16)(work->angle / 256)];
        if (work->negate == 1)
            height = -height;
        switch (work->arcAxis) {
        case ACMD_AXIS_X:
            offset.x = height;
            break;
        case ACMD_AXIS_Y:
            offset.y = height;
            break;
        case ACMD_AXIS_Z:
            offset.z = height;
            break;
        }
        func_0216D8C0(mmdl, &offset);
    }
    work->frames--;
    if (work->progress >= ACMD_GRID_FIXED && work->frames != 0) {
        int speed;
        int sign;

        work->progress -= ACMD_GRID_FIXED;
        sign = 1;
        speed = work->speed;
        func_0216D80C(mmdl, func_0216D83C(mmdl));
        func_0216D818(mmdl, func_0216D854(mmdl));
        func_0216D824(mmdl, func_0216D86C(mmdl));
        switch (work->moveAxis) {
        case ACMD_AXIS_X:
            if (speed < 0)
                sign = -1;
            func_0216D848(mmdl, sign);
            break;
        case ACMD_AXIS_Y:
            if (speed < 0)
                sign = -1;
            func_0216D860(mmdl, sign * 2);
            break;
        case ACMD_AXIS_Z:
            if (speed < 0)
                sign = -1;
            func_0216D87C(mmdl, sign);
            break;
        }
    }
    if (work->frames != 0)
        return 0;
    {
        MmdlVec offset = { 0, 0, 0 };
        func_0216D8C0(mmdl, &offset);
    }
    func_0216D568(mmdl, MMDL_MOVEBIT_MOVE_END | MMDL_MOVEBIT_JUMP_END | MMDL_MOVEBIT_ACMD_END);
    func_02163F10(mmdl);
    func_0216D674(mmdl, MMDL_DRAWSTA_STOP);
    func_0216D7CC(mmdl);
    return 1;
}

/* Jumps of 8 frames that move one grid and rise along height table 1, with the directions of the steps above. */
int func_02199AEC(Mmdl *mmdl)
{
    func_02199888(mmdl, ACMD_GRID_SPEED(8), MMDL_DIR_LEFT, MMDL_DIR_UP, 8, MMDL_DRAWSTA_WALK_8F, ACMD_AXIS_Y, ACMD_AXIS_Y, 0);
    return 1;
}

int func_02199B10(Mmdl *mmdl)
{
    func_02199888(mmdl, -ACMD_GRID_SPEED(8), MMDL_DIR_RIGHT, MMDL_DIR_DOWN, 8, MMDL_DRAWSTA_WALK_8F, ACMD_AXIS_Y, ACMD_AXIS_Y, 0);
    return 1;
}

int func_02199B38(Mmdl *mmdl)
{
    func_02199888(mmdl, ACMD_GRID_SPEED(8), MMDL_DIR_DOWN, MMDL_DIR_LEFT, 8, MMDL_DRAWSTA_WALK_8F, ACMD_AXIS_Z, ACMD_AXIS_Y, 0);
    return 1;
}

int func_02199B60(Mmdl *mmdl)
{
    func_02199888(mmdl, -ACMD_GRID_SPEED(8), MMDL_DIR_UP, MMDL_DIR_RIGHT, 8, MMDL_DRAWSTA_WALK_8F, ACMD_AXIS_Z, ACMD_AXIS_Y, 0);
    return 1;
}

int func_02199B88(Mmdl *mmdl)
{
    func_02199888(mmdl, ACMD_GRID_SPEED(8), MMDL_DIR_RIGHT, MMDL_DIR_UP, 8, MMDL_DRAWSTA_WALK_8F, ACMD_AXIS_Y, ACMD_AXIS_Y, 0);
    return 1;
}

int func_02199BAC(Mmdl *mmdl)
{
    func_02199888(mmdl, -ACMD_GRID_SPEED(8), MMDL_DIR_LEFT, MMDL_DIR_DOWN, 8, MMDL_DRAWSTA_WALK_8F, ACMD_AXIS_Y, ACMD_AXIS_Y, 0);
    return 1;
}

int func_02199BD8(Mmdl *mmdl)
{
    func_02199888(mmdl, -ACMD_GRID_SPEED(8), MMDL_DIR_UP, MMDL_DIR_LEFT, 8, MMDL_DRAWSTA_WALK_8F, ACMD_AXIS_Z, ACMD_AXIS_Y, 0);
    return 1;
}

int func_02199C00(Mmdl *mmdl)
{
    func_02199888(mmdl, ACMD_GRID_SPEED(8), MMDL_DIR_DOWN, MMDL_DIR_LEFT, 8, MMDL_DRAWSTA_WALK_8F, ACMD_AXIS_Z, ACMD_AXIS_Y, 0);
    return 1;
}

int func_02199C28(Mmdl *mmdl)
{
    func_02199888(mmdl, ACMD_GRID_SPEED(8), MMDL_DIR_DOWN, MMDL_DIR_UP, 8, MMDL_DRAWSTA_WALK_8F, ACMD_AXIS_Z, ACMD_AXIS_Y, 0);
    return 1;
}

int func_02199C50(Mmdl *mmdl)
{
    func_02199888(mmdl, -ACMD_GRID_SPEED(8), MMDL_DIR_UP, MMDL_DIR_DOWN, 8, MMDL_DRAWSTA_WALK_8F, ACMD_AXIS_Z, ACMD_AXIS_Y, 0);
    return 1;
}

int func_02199C7C(Mmdl *mmdl)
{
    func_02199888(mmdl, -ACMD_GRID_SPEED(8), MMDL_DIR_RIGHT, MMDL_DIR_LEFT, 8, MMDL_DRAWSTA_WALK_8F, ACMD_AXIS_X, ACMD_AXIS_Y, 0);
    return 1;
}

int func_02199CA4(Mmdl *mmdl)
{
    func_02199888(mmdl, ACMD_GRID_SPEED(8), MMDL_DIR_LEFT, MMDL_DIR_RIGHT, 8, MMDL_DRAWSTA_WALK_8F, ACMD_AXIS_X, ACMD_AXIS_Y, 0);
    return 1;
}

/* Walks in place for 22 frames. */
int func_02199CC8(Mmdl *mmdl)
{
    func_0216D6BC(mmdl, sizeof(AcmdCounterWork));
    func_0216D674(mmdl, MMDL_DRAWSTA_WALK_32F);
    func_0216D7CC(mmdl);
    return 0;
}

int func_02199CE4(Mmdl *mmdl)
{
    AcmdCounterWork *work;

    work = func_0216D6D4(mmdl);
    if (++work->count >= 22) {
        func_0216D7CC(mmdl);
    }
    return 0;
}

int func_02199D00(Mmdl *mmdl)
{
    func_0216D674(mmdl, MMDL_DRAWSTA_DASH_4F);
    func_0216D7CC(mmdl);
    return 1;
}

/* Moves one grid to the left in 2 frames with the 2 frame dash status. */
int func_02199D14(Mmdl *mmdl)
{
    AcmdWalkWork *work;

    work = func_0216D6BC(mmdl, sizeof(AcmdWalkWork));
    work->drawStatus = MMDL_DRAWSTA_DASH_2F;
    work->framesLeft = 2;
    work->dir = MMDL_DIR_LEFT;
    work->speed = ACMD_GRID_SPEED(2);
    func_02163E7C(mmdl, (u16)work->dir);
    func_0216D674(mmdl, work->drawStatus);
    func_0216D7CC(mmdl);
    return 1;
}

int func_02199D4C(Mmdl *mmdl)
{
    AcmdWalkWork *work;

    work = func_0216D6D4(mmdl);
    func_02163FC0(mmdl, (u16)work->dir, work->speed);
    func_02164010(mmdl);
    work->framesLeft = work->framesLeft - 1;
    if (work->framesLeft > 0) {
        return 0;
    }
    func_02163F10(mmdl);
    func_0216D7CC(mmdl);
    return 1;
}

/* Flies up out of sight: the model rises with a dash animation and wing sounds. */
int func_02199D8C(Mmdl *mmdl)
{
    AcmdFlyWork *work;

    work = func_0216D6BC(mmdl, sizeof(AcmdFlyWork));
    work->speed = ACMD_FLY_SPEED;
    work->elapsed = 0;
    work->lastFrame = 0;
    func_0216D674(mmdl, MMDL_DRAWSTA_DASH_6F);
    func_0216D7CC(mmdl);
    return 1;
}

int func_02199DB4(Mmdl *mmdl)
{
    AcmdFlyWork *work;
    u16 animeState;
    u16 animeFrame;

    work = func_0216D6D4(mmdl);
    if (func_0219FC68(mmdl, &animeState, &animeFrame) != 1)
        return 0;
    work->elapsed = work->elapsed + 1;
    animeFrame = animeFrame - 1;
    if (func_0216D598(mmdl) == MMDL_OBJCODE_FLY_A) {
        if (animeState == 2 && work->lastFrame != animeFrame) {
            work->lastFrame = animeFrame;
            switch (animeFrame) {
            case 7:
            case 12:
            case 17:
                func_020061E4(SE_FLY_FLAP_A);
                break;
            case 10:
            case 15:
            case 20:
                func_020061E4(SE_FLY_FLAP_B);
                break;
            }
        }
    } else if (work->elapsed == ACMD_FLY_TAKEOFF_FRAMES) {
        func_020061E4(SE_FLY_TAKEOFF);
    }
    if (work->elapsed < ACMD_FLY_TAKEOFF_FRAMES)
        return 0;
    work->height += work->speed;
    {
        MmdlVec offset = { 0, 0, 0 };
        offset.y = work->height;
        func_0216D8C0(mmdl, &offset);
    }
    if (work->height / 0x8000 < 16)
        return 0;
    func_0216D674(mmdl, MMDL_DRAWSTA_STOP);
    func_0216D7CC(mmdl);
    return 1;
}

int func_02199EAC(Mmdl *mmdl)
{
    func_0216D674(mmdl, MMDL_DRAWSTA_DASH_4F);
    func_0216D7CC(mmdl);
    return 1;
}

int func_02199EC0(Mmdl *mmdl)
{
    func_0216D674(mmdl, MMDL_DRAWSTA_DASH_6F);
    func_0216D7CC(mmdl);
    return 0;
}

/* Waits for the end of the draw animation, then faces down and stops the draw status. */
int func_02199ED4(Mmdl *mmdl)
{
    void *blActSys;
    u32 animeId;
    u16 animeFlag;

    blActSys = func_0219C9DC(func_0216D520(func_0216D67C(mmdl)));
    animeId = func_0216D7A8(mmdl, 0);
    if (animeId != 0xFFFF) {
        if (func_020508EC(blActSys, (u16)animeId, &animeFlag) == 0) {
            return 0;
        }
    }
    func_0216D5E0(mmdl, MMDL_DIR_DOWN);
    func_0216D674(mmdl, MMDL_DRAWSTA_STOP);
    func_0216D7CC(mmdl);
    return 1;
}

int func_02199F30(Mmdl *mmdl)
{
    MmdlVec offset = { 0, 0, 0 };

    func_0216D8C0(mmdl, &offset);
    func_0216D7CC(mmdl);
    return 1;
}

/* Starts the wait before the flight: the model hovers half a grid up with a dash animation. */
int func_02199F50(Mmdl *mmdl)
{
    AcmdFlyReadyWork *work;
    MmdlVec offset = d_021D4ACC;

    work = func_0216D6BC(mmdl, sizeof(AcmdFlyReadyWork));
    work->elapsed = 0;
    work->lastFrame = 0;
    func_0216D8C0(mmdl, &offset);
    func_0216D674(mmdl, MMDL_DRAWSTA_DASH_4F);
    func_0216D7CC(mmdl);
    return 1;
}

int func_02199F94(Mmdl *mmdl)
{
    AcmdFlyReadyWork *work;
    u16 animeState;
    u16 animeFrame;

    work = func_0216D6D4(mmdl);
    if (func_0219FCC0(mmdl, &animeState, &animeFrame) != 1)
        return 0;
    work->elapsed = work->elapsed + 1;
    animeFrame = animeFrame - 1;
    if (func_0216D598(mmdl) == MMDL_OBJCODE_FLY_B && animeState == 0 && work->lastFrame != animeFrame) {
        work->lastFrame = animeFrame;
        switch (animeFrame) {
        case 0:
            func_020061E4(SE_FLY_FLAP_A);
            break;
        case 3:
            func_020061E4(SE_FLY_FLAP_B);
            break;
        }
    }
    if (work->elapsed < ACMD_FLY_TAKEOFF_FRAMES)
        return 0;
    func_0216D7CC(mmdl);
    return 1;
}

int func_0219A014(Mmdl *mmdl)
{
    func_0216D674(mmdl, MMDL_DRAWSTA_DASH_4F);
    func_0216D7CC(mmdl);
    return 0;
}

int func_0219A028(Mmdl *mmdl)
{
    func_0216D674(mmdl, MMDL_DRAWSTA_DASH_6F);
    func_0216D7CC(mmdl);
    return 0;
}

int func_0219A03C(Mmdl *mmdl)
{
    func_0216D674(mmdl, MMDL_DRAWSTA_DASH_2F);
    func_0219FE64(mmdl);
    func_0216D7CC(mmdl);
    return 0;
}

/* Waits until the draw object is ready, then stops the draw status. */
int func_0219A058(Mmdl *mmdl)
{
    if (func_0219FE20(mmdl) == 1) {
        func_0216D674(mmdl, MMDL_DRAWSTA_STOP);
        func_0216D7CC(mmdl);
        return 1;
    }
    return 0;
}

int func_0219A07C(Mmdl *mmdl)
{
    if (func_0219FE20(mmdl) == 1) {
        func_0216D7CC(mmdl);
        return 1;
    }
    return 0;
}
