/*
 * file:     field_event_check.c
 * unit:     yes
 * function: func_02189BBC, func_02189BD0, func_0218A074, func_0218A0E4, func_0218A240, func_0218A278, func_0218A4BC, func_0218A4E0, func_0218A6E8, func_0218A728, func_0218A738, func_0218A76C, func_0218A784, func_0218A7F0, func_0218A824, func_0218A878, func_0218A8BC, func_0218A9B0, func_0218AA2C, func_0218AA74, func_0218AAD0, func_0218AB0C, func_0218AB50, func_0218AB9C, func_0218AC08, func_0218AC4C, func_0218AC84, func_0218ACA8, func_0218ACD0, func_0218AD28, func_0218AD80, func_0218ADC8, func_0218AE04, func_0218AE48, func_0218AEAC, func_0218AECC, func_0218AED4, func_0218AF90, func_0218B0CC, func_0218B13C, func_0218B208, func_0218B24C, func_0218B2A8, func_0218B2E8, func_0218B310, func_0218B32C, func_0218B3DC, func_0218B408, func_0218B4B0, func_0218B53C, func_0218B56C, func_0218B630, func_0218B6AC, func_0218B6F8
 * address:  0x02189BBC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from field_msgbg.c: event checks run each frame by fieldmap.c (talk, background, position and step events, input). No __FILE__ anchor; file name is a guess. TU boundary before 0x02189BBC is proven (tuboundary).
 *
 * symbols:
 *   func_02189B28  0x02189B28  thumb  ov021
 *   d_021D373C     0x021D373C  data  a4
 *   func_02012ED0  0x02012ED0  thumb
 *   func_021C868C  0x021C868C  thumb
 *   func_021AE0CC  0x021AE0CC  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_020142E8  0x020142E8  thumb
 *   func_021A2F20  0x021A2F20  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_021A3074  0x021A3074  thumb
 *   func_0217BFD8  0x0217BFD8  thumb  ov018
 *   func_0217CA84  0x0217CA84  thumb  ov018
 *   func_02026454  0x02026454  thumb
 *   func_02012B70  0x02012B70  thumb
 *   func_0217C070  0x0217C070  thumb  ov018
 *   func_0217B810  0x0217B810  thumb  ov018
 *   func_0217689C  0x0217689C  thumb  ov011
 *   func_02012FB0  0x02012FB0  thumb
 *   func_0216B3A8  0x0216B3A8  thumb  ov010
 *   func_021754B4  0x021754B4  thumb  ov011
 *   func_021A2F6C  0x021A2F6C  thumb
 *   func_0217FC6C  0x0217FC6C  thumb  ov018
 *   func_0217BDE0  0x0217BDE0  thumb  ov018
 *   func_0217AFC4  0x0217AFC4  thumb  ov018
 *   func_0217FB5C  0x0217FB5C  thumb  ov018
 *   func_021A3050  0x021A3050  thumb
 *   func_021A3038  0x021A3038  thumb
 *   func_02164208  0x02164208  thumb  ov010
 *   func_0216D5B8  0x0216D5B8  thumb  ov010
 *   func_02158D90  0x02158D90  thumb  ov010
 *   func_0219F01C  0x0219F01C  thumb
 *   func_02162A54  0x02162A54  thumb  ov010
 *   func_02158768  0x02158768  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BE48  0x0200BE48  thumb
 *   func_02188C9C  0x02188C9C  thumb
 *   func_021CFAC0  0x021CFAC0  thumb
 *   func_021CFC14  0x021CFC14  thumb
 *   func_021CD440  0x021CD440  thumb
 *   func_02013FFC  0x02013FFC  thumb
 *   func_02162940  0x02162940  thumb  ov010
 *   func_020221A4  0x020221A4  thumb
 *   func_02188CCC  0x02188CCC  thumb
 *   func_0215FF34  0x0215FF34  thumb  ov010
 *   func_021A0ED4  0x021A0ED4  thumb
 *   func_0215FF54  0x0215FF54  thumb  ov010
 *   func_0201212C  0x0201212C  thumb
 *   func_021C06CC  0x021C06CC  thumb
 *   func_021A0F90  0x021A0F90  thumb
 *   func_0215FC40  0x0215FC40  thumb  ov010
 *   func_021A0EB0  0x021A0EB0  thumb
 *   func_0217B410  0x0217B410  thumb  ov018
 *   func_0201210C  0x0201210C  thumb
 *   func_02188CE8  0x02188CE8  thumb  ov021
 *   func_021AA8F8  0x021AA8F8  thumb  ov021
 *   func_021AA8EC  0x021AA8EC  thumb  ov021
 *   func_02188D20  0x02188D20  thumb  ov021
 *   func_021BC5BC  0x021BC5BC  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3550  0x021A3550  thumb  ov021
 *   func_021A356C  0x021A356C  thumb  ov021
 *   func_02189A70  0x02189A70  thumb  ov021
 *   func_021F3B10  0x021F3B10  thumb  ov053
 *   func_02026474  0x02026474  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   func_021850FC  0x021850FC  thumb  ov020
 *   func_0217391C  0x0217391C  thumb  ov012
 *   func_02173928  0x02173928  thumb  ov012
 *   func_02026400  0x02026400  thumb
 *   func_0217B80C  0x0217B80C  thumb  ov019
 *   func_0217B83C  0x0217B83C  thumb  ov019
 *   func_0217394C  0x0217394C  thumb  ov012
 *   func_0216D588  0x0216D588  thumb  ov010
 *   func_0217AF38  0x0217AF38  thumb  ov019
 *   func_0215FCE0  0x0215FCE0  thumb  ov010
 *   func_0219E634  0x0219E634  thumb  ov021
 *   func_0219E2F4  0x0219E2F4  thumb  ov021
 *   func_02162958  0x02162958  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_02162A5C  0x02162A5C  thumb  ov010
 *   func_02188CFC  0x02188CFC  thumb  ov021
 *   func_02188C84  0x02188C84  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012844  0x02012844  thumb
 *   func_021A2FE4  0x021A2FE4  thumb
 *   func_021A3080  0x021A3080  thumb
 *   func_021A308C  0x021A308C  thumb
 *   func_0216D888  0x0216D888  thumb  ov010
 *   func_02012B38  0x02012B38  thumb
 *   func_02014478  0x02014478  thumb
 *   func_021A30C8  0x021A30C8  thumb
 *   func_021A3584  0x021A3584  thumb
 *   func_021A1358  0x021A1358  thumb  ov021
 *   func_02012A30  0x02012A30  thumb
 *   func_02028A70  0x02028A70  thumb
 *   func_021F2AB8  0x021F2AB8  thumb  ov029
 *   func_021F2AD4  0x021F2AD4  thumb  ov029
 *   func_02012F2C  0x02012F2C  thumb
 *   func_02008DF0  0x02008DF0  thumb
 *   func_02014474  0x02014474  thumb
 *   func_02158B00  0x02158B00  thumb  ov010
 *   func_02188C98  0x02188C98  thumb
 *   func_021AB0D4  0x021AB0D4  thumb
 *   func_021AB0F0  0x021AB0F0  thumb
 *   func_021AB188  0x021AB188  thumb
 *   func_02162928  0x02162928  thumb  ov010
 *   func_021A2FA4  0x021A2FA4  thumb
 *   func_0217B4D8  0x0217B4D8  thumb ov018
 *   func_02013D5C  0x02013D5C  thumb
 *   func_0216282C  0x0216282C  thumb  ov010
 *   func_021A3098  0x021A3098  thumb
 *   func_0216D7C4  0x0216D7C4  thumb  ov010
 *   func_02188C80  0x02188C80  thumb
 *   func_02008970  0x02008970  thumb
 *   func_0200896C  0x0200896C  thumb
 *   func_02012934  0x02012934  thumb
 *   func_02188D50  0x02188D50  thumb
 *   func_021C3378  0x021C3378  thumb
 *   func_02008978  0x02008978  thumb
 *   func_02008980  0x02008980  thumb
 *   func_02008854  0x02008854  thumb
 *   func_021D220C  0x021D220C  thumb
 *   func_02008990  0x02008990  thumb
 *   func_02008988  0x02008988  thumb
 *   func_0200D564  0x0200D564  thumb
 *   func_021AA944  0x021AA944  thumb
 *   func_021AA80C  0x021AA80C  thumb
 *   func_02010F18  0x02010F18  thumb
 *   func_020124AC  0x020124AC  thumb
 *   abs_id_83      0x00000053  data
 *   func_021F532C  0x021F532C  thumb  ov083
 *   func_021625CC  0x021625CC  thumb  ov010
 *   func_021626EC  0x021626EC  thumb  ov010
 *   func_021C8A74  0x021C8A74  thumb
 *   func_021C8A30  0x021C8A30  thumb
 *   func_021C8CF0  0x021C8CF0  thumb
 *   func_021C8C88  0x021C8C88  thumb
 *   func_021626A8  0x021626A8  thumb  ov010
 *   func_021626E8  0x021626E8  thumb  ov010
 *   func_02185410  0x02185410  thumb  ov020
 *   func_02185360  0x02185360  thumb  ov020
 *   func_02014110  0x02014110  thumb
 *   func_02012878  0x02012878  thumb
 *   func_02162564  0x02162564  thumb  ov010
 *   func_021626B8  0x021626B8  thumb  ov010
 *   func_021AB0F8  0x021AB0F8  thumb  ov021
 *   func_021BE288  0x021BE288  thumb  ov021
 *   func_021F3A88  0x021F3A88  thumb  ov038
 *   func_021F38A4  0x021F38A4  thumb  ov051
 *   func_021AB310  0x021AB310  thumb  ov021
 *   func_02163E58  0x02163E58  thumb  ov010
 *   func_021F404C  0x021F404C  thumb  ov039
 *   func_021F37E0  0x021F37E0  thumb  ov041
 *   func_02162598  0x02162598  thumb  ov010
 *   func_02013DD0  0x02013DD0  thumb
 *   func_021AA248  0x021AA248  thumb
 *   func_021A9F40  0x021A9F40  thumb
 *   func_021BB188  0x021BB188  thumb
 *   func_0219E418  0x0219E418  thumb
 *   func_021C46F8  0x021C46F8  thumb
 *   func_02014134  0x02014134  thumb
 *   func_021626B0  0x021626B0  thumb  ov010
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_021A2F98  0x021A2F98  thumb
 *   func_021ACBB8  0x021ACBB8  thumb
 *   func_021A2F48  0x021A2F48  thumb
 *   func_021A2F60  0x021A2F60  thumb  ov021
 *   func_02197E7C  0x02197E7C  thumb
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_021A2FD0  0x021A2FD0  thumb
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 *   func_021A35A0  0x021A35A0  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_021A3364  0x021A3364  thumb
 *   func_021AB2E8  0x021AB2E8  thumb
 *   func_021A3460  0x021A3460  thumb
 *   func_02164294  0x02164294  thumb  ov010
 *   func_021AB194  0x021AB194  thumb
 *   func_02164240  0x02164240  thumb  ov010
 *   func_02188C7C  0x02188C7C  thumb
 *   func_0216D8AC  0x0216D8AC  thumb  ov010
 *   func_0216DDDC  0x0216DDDC  thumb  ov010
 *   func_0219E570  0x0219E570  thumb  ov021
 *   func_021A3128  0x021A3128  thumb
 *   func_02013E04  0x02013E04  thumb
 *   func_021A3504  0x021A3504  thumb
 *   func_021A3524  0x021A3524  thumb
 *   data_021D3CE8  0x021D3CE8  data
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_021641E8  0x021641E8  thumb  ov010
 *   func_021641F8  0x021641F8  thumb  ov010
 *   func_0216DDC0  0x0216DDC0  thumb  ov010
 *   func_02082BCC  0x02082BCC  arm
 *   func_020362DC  0x020362DC  arm
 *   func_0203630C  0x0203630C  arm
 *   func_0218DC70  0x0218DC70  thumb  ov021
 */
#include "fieldmap_types.h"
#include "fldmmdl_rail_types.h"

typedef unsigned int u32;
typedef signed int s32;

struct GameEvent;
struct EventDataSystem;

/*
 * The per-frame field input record (0x40 bytes), built on the stack by
 * FIELD_EVENT_CHECK_InitInput and read by every check of this file.
 */
typedef struct FieldEventInput {
    u16 heapId;                 /*
0x00: field heap id of the field map
 */
    u16 heapIdPad;              /*
0x02
 */
    void *gameSystem;           /*
0x04
 */
    void *gameData;             /*
0x08
 */
    void *eventData;            /*
0x0C: map event data (EventDataSystem)
 */
    u16 zoneId;                 /*
0x10
 */
    u16 zoneIdPad;              /*
0x12
 */
    FieldMap *fieldMap;         /*
0x14
 */
    void *player;               /*
0x18: field player
 */
    u32 moveState;              /*
0x1C: player move state, 3 = step finished
 */
    u32 moveMode;               /*
0x20: player move mode (1 walk, 2 other)
 */
    u16 facingDir;              /*
0x24: dir of the player model
 */
    u16 pendingScriptId;        /*
0x26: script id queued by a proc action
 */
    u32 keyTrg;                 /*
0x28: pad trigger
 */
    u32 keyCont;                /*
0x2C: pad held
 */
    u16 heldDir;                /*
0x30: direction of the held d-pad, 9 none
 */
    u16 heldDirPad;             /*
0x32
 */
    VecFx32 *playerPos;         /*
0x34: position of the player model
 */
    u32 tileAttr;               /*
0x38: tile attribute under the player
 */
    u32 aPressed : 1;           /*
0x3C bit 0: A pressed, talk
 */
    u32 xPressed : 1;           /*
bit 1: X pressed, menu
 */
    u32 walkStepDone : 1;       /*
bit 2: step finished while walking
 */
    u32 stepDone : 1;           /*
bit 3: step finished
 */
    u32 otherMoveBusy : 1;      /*
bit 4: unfinished move of mode 2
 */
    u32 pushingFacing : 1;      /*
bit 5: held d-pad matches the facing
 */
    u32 yPressed : 1;           /*
bit 6: Y pressed, registered item
 */
    u32 noButton : 1;           /*
bit 7: no button pressed
 */
    u32 padBit8 : 1;            /*
bit 8: never set
 */
    u32 tileChanged : 1;        /*
bit 9: player entered a new tile
 */
    u32 inputEnabled : 1;       /*
bit 10: move state allows input
 */
} FieldEventInput;

/*
Position event record (PosEventData, 0x16 bytes, eventdata_system.c).
 */
typedef struct PosEvent {
    u16 scriptId;               /*
0x00
 */
    u16 workValue;              /*
0x02
 */
    u16 workId;                 /*
0x04
 */
    u16 checkType;              /*
0x06
 */
    u16 posType;                /*
0x08: 0 grid area
 */
    struct {
        u16 x;
        u16 z;
        u16 width;
        u16 height;
    } area;                     /*
0x0A
 */
} PosEvent;

/*
Work of the ledge jump task (0x10 bytes).
 */
typedef struct LedgeJumpWork {
    int reserved;               /*
0x00
 */
    u16 dir;                    /*
0x04
 */
    u16 jumpTwoTiles;           /*
0x06
 */
    void *gameSystem;           /*
0x08
 */
    FieldMap *fieldMap;         /*
0x0C
 */
} LedgeJumpWork;

/*
Message shown for the tile the player faces (table at data_021D3CE8).
 */
struct TileMessage {
    int (*test)(u16 attr);
    u16 dir;
    u16 scriptId;
};

extern u32 *func_02012ED0(void *p);
extern int func_021C868C(int a, char *b);
extern int func_021AE0CC(int a);
extern u32 func_0201296C(const void *p);
extern u32 func_020142E8(void *bitmap, s32 id);
extern int func_021A2F20(u32 *p, int a, int b, int c);
extern u32 func_02012138(const void *p);
extern int func_02158344(int a0);
extern void *func_021A3074(u8 *);
extern int func_0217BFD8(const void *a, int b);
extern int func_0217CA84(void *sys, int v);
extern u32 func_02026454(void *obj);
extern int func_02012B70(const void *p);
extern int func_0217C070(u8 *p);
extern void *func_0217B810(void *a, FieldMap *fieldMap);
extern int func_0217689C(u8 *ctx, int arg);
extern int func_02012FB0(unsigned char *base);
extern struct GameEvent *func_0216B3A8(int a0, int a1, int a2);
extern int func_021754B4(u8 *p, int *out);
extern void func_021A2F6C(u32 *p);
extern void *func_0217FC6C(void *p, int a, int b, int c, int d, u16 e);
extern int func_0217BDE0(int a, u8 *b, void *player);
extern int func_0217AFC4(int *a, u8 *b, int *out);
extern void *func_0217FB5C(void *owner, int b, int unused, int d, int e, u16 f);
extern u16 func_021A3050(u8 *p);
extern void func_021A3038(u8 *, VecFx32 *);
extern void func_02164208(int dir, int *p, int amt);
extern u32 func_0216D5B8(void *p);
extern int func_02158D90(u16 v);
extern int func_0219F01C(u32 a, u32 b, u32 c, u32 e0, u32 e1, u16 id);
extern u32 func_02162A54(void *p, void *q, int *pos, u32 d);
extern struct GameEvent *func_02158768(int a0, int a1, int a2, int a3);
extern void *func_02012EBC(void *p);
extern u16 *func_0200BE48(void *sys);
extern u16 func_02188C9C(FieldMap *fieldMap);
extern int func_021CFAC0(u8 *base, int a, int b, int c, int d);
extern void *func_021CFC14(void *a, u16 heapId, void *c);
extern int func_021CD440(void *a, u16 *out);
extern u32 func_02013FFC(u32 id);
extern u16 func_02162940(void *p, void *q, int key);
extern u32 func_020221A4(void);
extern u32 func_02188CCC(FieldMap *fieldMap);
extern int func_0215FF34(void *sys);
extern int func_021A0ED4(u32 a);
extern struct GameEvent *func_0215FF54(int a0, int a1, u16 a2);
extern u8 func_0201212C(const void *p);
extern int func_021C06CC(void *sys, FieldMap *fieldMap);
extern u32 func_021A0F90(u8 *p);
extern struct GameEvent *func_0215FC40(int a0, int a1, u16 a2);
extern int func_021A0EB0(u32 *p, u32 a);
extern int func_0217B410(int a0, int a1, void *player);
extern void *func_0201210C(const void *p);
extern u32 func_02188CE8(FieldMap *fieldMap);
extern void func_021AA8F8(void);
extern void func_021AA8EC(u8 *p);
extern u32 func_02188D20(FieldMap *fieldMap);
extern int func_021BC5BC(u8 *a);
extern void *func_02188CB4(FieldMap *fieldMap);
extern void func_021A3550(u32 *p, int a);
extern void func_021A356C(void **p);
extern u32 func_02189A70(FieldMap *fieldMap);
extern void func_021F3B10(void);
extern u32 func_02026474(void *obj);
extern u32 func_0200FB24(void);
extern void *func_021850FC(void *p, FieldMap *fieldMap);
extern int func_0217391C(u8 *p);
extern int func_02173928(u8 *p);
extern void func_02026400(void *p);
extern int func_0217B80C(int a, int b);
extern int func_0217B83C(void *sys, void *pos);
extern int func_0217394C(const void *p);
extern u16 func_0216D588(void *p);
extern int func_0217AF38(u16 a);
extern int func_0215FCE0(int a, int b, unsigned short c);
extern int func_0219E634(void *, RailLocation *);
extern void func_0219E2F4(void *o, RailLocation *out);
extern u16 func_02162958(void *c, void *a, RailLocation *key);
extern u16 func_0216D5F8(void *obj);
extern u16 func_02162A5C(void *set, void *flags, const RailLocation *where, u16 type);
extern u32 func_02188CFC(FieldMap *fieldMap);
extern u32 func_02082BCC(void *, int, u32);
extern u16 func_02188C84(FieldMap *fieldMap);
extern void *func_020120F4(const void *p);
extern u32 func_02012844(const void *p);
extern u32 func_020362DC(void);
extern unsigned int func_0203630C(void);
extern void func_021A2FE4(u32 *p);
extern u32 func_021A3080(u8 *p);
extern u32 func_021A308C(u8 *p);
extern void *func_0216D888(void *p);
extern void *func_02012B38(const void *p);
extern u16 func_02014478(void *o);
extern u32 func_021A30C8(void **ctx);
extern int func_021A3584(void *v);
extern u32 func_021A1358(u32 *p);
extern u32 func_02012A30(const void *p);
extern void func_02028A70(void *sys);
extern int func_021F2AB8(char *p);
extern void func_021F2AD4(u8 *p);
extern u32 func_02008DF0(void *obj, int i);
extern void *func_02012F2C(int *p);
extern void func_02014474(void *o, u16 v);
extern void *func_02158B00(void *a, u32 b);
extern u32 func_02188C98(FieldMap *fieldMap);
extern int func_021AB0D4(void *a, void *b);
extern u16 func_021AB0F0(u32 attr);
extern int func_021AB188(u16 id);
extern u16 func_02162928(void *p, void *q, int key, int mode);
extern u16 func_021A2FA4(u8 *p, u32 a1);
extern u32 func_02013D5C(u32 id);
extern void *func_0217B4D8(void *a, void *b, void *c, int *d, u16 e, int f);
extern void *func_0216282C(void *c, void *a, int *key, int mode);
extern u32 func_021A3098(u8 *p);
extern u16 func_0216D7C4(u8 *p);
extern void *func_02188C80(FieldMap *fieldMap);
extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *mon, u32 id, u32 v);
extern void func_02017E40(void *mon, u32 id, u32 v);
extern void *func_02008854(void *sys);
extern void func_02008970(const void *obj, u32 *out);
extern void func_0200896C(void *obj, u32 value);
extern u32 func_02010FF4(u32 v);
extern void *func_02012934(const void *p);
extern void *func_02188D50(FieldMap *fieldMap);
extern int func_021C3378(void **p);
extern u16 func_02008978(const void *obj);
extern void func_02008980(void *obj, u16 value);
extern void func_0201B7EC(void *mon, int a, int b);
extern int func_021D220C(void *gameSystem, FieldMap *fieldMap);
extern u16 func_02008990(const void *obj);
extern void func_02008988(void *obj, u16 value);
extern void *func_0200D418(void *p);
extern u32 func_0200D564(void *p);
extern int func_021AA944(void *self);
extern void func_021AA80C(void *ctx);
extern u8 func_02010F18(void);
extern struct GameEvent *func_020124AC(void *a0, u32 a1, u32 (*fn)(void *, u32), u32 a3);
extern void func_021F532C(void *p);
extern void *func_021625CC(char *p, unsigned i);
extern int func_021626EC(u16 *p);
extern int func_021C8A74(u32 a);
extern void *func_021C8A30(u32 prio, void *sys, void *owner);
extern int func_021C8CF0(u32 a);
extern void *func_021C8C88(u32 prio, void *sys, void *owner);
extern u16 func_021626A8(void *b, void *pos);
extern u8 func_021626E8(u8 *p);
extern void *func_02185410(void *p, int u, int a, int b);
extern void *func_02185360(void *p, int u, int a, int b);
extern void func_02014110(void *p, u16 a, s16 b, u16 c, u16 d, u32 e, u32 f, u32 g);
extern void func_02012878(void *p, const void *src);
extern int func_02162564(void *eventData, VecFx32 *pos);
int func_021626B8(char *a0, int a1);
extern u16 func_021AB0F8(u32 attr);
extern int func_021BE288(FieldMap *fieldMap, int k);
extern int func_021F3A88(int a0, int a1, int a2);
extern int func_021F38A4(int a, int b);
extern int func_021AB310(u16 a);
extern int func_02163E58(void *m, VecFx32 *pos, int *h);
extern int func_021F404C(void *a);
extern int func_021F37E0(void *a);
extern int func_02162598(void *eventData, RailLocation *location);
extern int func_02013DD0(int a0);
extern int func_021AA248(void *ctx, void *b);
extern int func_021A9F40(void *ctx, int mode);
extern int func_021BB188(u16 a);
extern int func_0219E418(u32 a, u32 b);
extern u32 func_021C46F8(u32 a, u32 b, u32 c);
extern void func_02014134(u8 *p, u16 b, int c, u16 d, u16 e, u16 f, u16 g, s16 h);
extern u16 func_021626B0(void *b, void *q);
extern void *func_0216D67C(void *o);
extern void func_0216D9A0(void *o);
extern void func_0216D5E0(int a0, int a1);
extern u32 func_021A2F98(u8 *p);
extern void func_021ACBB8(u32 a, u8 v);
extern void func_021A2F48(u8 *p, u32 a1);
extern void func_021A2F60(int *p);
extern int func_02197E7C(int a, int b);
extern void func_0216D410(void *o, int a);
extern int func_0216D454(void *o);
extern int func_021A2FD0(void *a);
extern u32 *func_0216D9E4(void *c);
extern void func_021A35A0(u32 *p, int a);
struct GameEvent *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(void *p);
extern void func_021A3364(u32 *a, int b, int *out);
extern int func_021AB2E8(int a);
extern int func_021A3460(u32 a, u32 b, u32 c, u32 d);
extern void func_02164294(int x, int y, int z, int *out);
extern int func_021AB194(u16 id);
extern void func_02164240(int dir, s16 *x, s16 *z, s16 amt);
extern void *func_02188C7C(FieldMap *fieldMap);
extern u32 func_0216D8AC(void *p);
extern u8 *func_0216DDDC(u32 a, u32 b, u32 c, s32 x, s32 lim, u32 d);
u32 func_0219E570(u32 o, u32 k, u32 flag);
extern u32 func_021A3128(u32 *a, u32 b);
extern u32 func_02013E04(u32 id);
extern int func_021A3504(u8 *a, int b, int c);
extern int func_021A3524(u8 *a, int b, int c);
extern int func_0216D83C(void *o);
extern int func_0216D86C(void *o);
extern int func_021641E8(u16 d);
extern int func_021641F8(u16 d);
extern void *func_0216DDC0(u32 a, u32 b, u32 c, u32 d);
void *func_0218DC70(u8 *p);
extern FieldMapTypeEntryTail d_021D373C[];
extern u8 abs_id_83[];
extern const struct TileMessage data_021D3CE8[13];


int func_02189BBC(int zoneId);
int func_02189BD0(void *gameSystem, FieldMap *fieldMap, int *outResetEncount, int *outMenuRequest);
int func_0218A074(void *gameSystem, FieldMap *fieldMap);
int func_0218A0E4(void *gameSystem, FieldMap *fieldMap);
int func_0218A240(void *gameSystem, FieldMap *fieldMap);
int func_0218A278(void *gameSystem, FieldMap *fieldMap);
int func_0218A4BC(void *gameSystem, FieldMap *fieldMap, u32 unusedC, u32 unusedD);
void func_0218A4E0(FieldEventInput *input, void *gameSystem, FieldMap *fieldMap);
void func_0218A6E8(void *gameSystem, FieldMap *fieldMap);
int func_0218A728(void *gameData);
int func_0218A738(FieldEventInput *input);
int func_0218A76C(FieldEventInput *input);
int func_0218A784(FieldEventInput *input, int dir);
int func_0218A7F0(FieldEventInput *input);
int func_0218A824(FieldEventInput *input);
void *func_0218A878(FieldEventInput *input, void *gameSystem, FieldMap *fieldMap);
int func_0218A8BC(FieldEventInput *input);
int func_0218A9B0(FieldEventInput *input, FieldMap *fieldMap);
int func_0218AA2C(void *party);
void func_0218AA74(void *party);
void func_0218AAD0(void *gameData, void *party);
int func_0218AB0C(void *party);
int func_0218AB50(FieldEventInput *input, FieldMap *fieldMap, void *gameSystem, void *gameData);
void func_0218AB9C(void *gameData, FieldMap *fieldMap);
int func_0218AC08(void *gameSystem, FieldMap *fieldMap, u16 zoneId);
int func_0218AC4C(FieldMap *fieldMap, void *gameSystem, void *gameData);
int func_0218AC84(FieldMap *fieldMap, void *gameSystem, void *gameData);
struct GameEvent *func_0218ACA8(void *gameSystem);
int func_0218ACD0(FieldEventInput *input, FieldMap *fieldMap, VecFx32 *pos);
void *func_0218AD28(FieldEventInput *input, FieldMap *fieldMap);
int func_0218AD80(FieldEventInput *input, FieldMap *fieldMap, int connectId, VecFx32 *pos);
void func_0218ADC8(FieldEventInput *input, int connectId, VecFx32 *pos);
u32 func_0218AE04(FieldEventInput *input, VecFx32 *pos);
void func_0218AE48(FieldEventInput *input, VecFx32 *out);
int func_0218AEAC(void *connect);
int func_0218AECC(void *connect, int dir);
int func_0218AED4(FieldEventInput *input, int unused, FieldMap *fieldMap);
int func_0218AF90(FieldEventInput *input, void *gameSystem, FieldMap *fieldMap);
int func_0218B0CC(FieldEventInput *input, void *unused, FieldMap *fieldMap);
int func_0218B13C(FieldEventInput *input, void *unused, FieldMap *fieldMap, RailLocation *frontLocation);
int func_0218B208(FieldEventInput *input, void *unused, FieldMap *fieldMap);
int func_0218B24C(FieldEventInput *input, void *gameSystem, FieldMap *fieldMap);
void func_0218B2A8(FieldEventInput *input, int connectId, RailLocation *location);
int func_0218B2E8(FieldEventInput *input, FieldMap *fieldMap, int connectId, RailLocation *location);
int func_0218B310(void *player, FieldEventInput *input);
int func_0218B32C(void *task, int *seq, LedgeJumpWork *work);
int func_0218B3DC(int unused, void *gameSystem, FieldMap *fieldMap, int dir, int jumpTwoTiles);
int func_0218B408(FieldEventInput *input, void *gameSystem, FieldMap *fieldMap);
int func_0218B4B0(FieldEventInput *input, FieldMap *fieldMap);
int func_0218B53C(FieldEventInput *input, FieldMap *fieldMap);
u16 func_0218B56C(FieldEventInput *input, FieldMap *fieldMap);
int func_0218B630(void *gameData, u32 move);
int func_0218B6AC(void *gameSystem);
int func_0218B6F8(FieldEventInput *input, FieldMap *fieldMap);

int func_02189BBC(int zoneId)
{
    return d_021D373C[(int)func_02189B28((unsigned int)zoneId)].extra;
}


/*
 * Root of the field input tree: builds the field input record on the stack
 * and runs the talk / step / menu / surf / script checks in order,
 * returning the first non-zero result.  The u16 local at sp+0x28 is the
 * out slot of func_021CD440; its address doubles as the base for the
 * in.heapId / in.zoneId loads, which is why `add r1, sp, #0x28` sits above the
 * beq after the func_021CFAC0 test.
 */
int func_02189BD0(void *gameSystem, FieldMap *fieldMap, int *outResetEncount, int *outMenuRequest)
{
    FieldEventInput input;
    int frontPos[3];
    u32 commTarget;
    u16 areaZoneId;
    int result;
    u32 blockFlags;
    void *commWork;
    void *gameComm;
    void *playerMmdl;

    *outResetEncount = 0;
    *outMenuRequest = 0;
    func_0218A4E0(&input, gameSystem, fieldMap);
    result = func_0218A738(&input);
    if (result != 0) {
        *outResetEncount = 1;
        return result;
    }
    result = func_021C868C((int)gameSystem, (char *)(*func_02012ED0(input.gameData)));
    if (result != 0)
        return result;
    result = func_021AE0CC((int)fieldMap);
    if (result != 0) {
        *outResetEncount = 1;
        return result;
    }
    if (input.walkStepDone)
        func_0218A728(input.gameData);
    if (input.walkStepDone) {
        result = func_0218A76C(&input);
        if (result != 0) {
            *outResetEncount = 1;
            return result;
        }
        result = func_0218ACD0(&input, fieldMap, input.playerPos);
        if (result != 0)
            return result;
        result = (int)func_0218AD28(&input, fieldMap);
        if (result != 0)
            return result;
    }
    result = func_0218A9B0(&input, fieldMap);
    if (result != 0)
        return result;
    if (input.stepDone) {
        result = func_0218A7F0(&input);
        if (result != 0)
            return result;
    }
    result = func_0218A824(&input);
    if (result != 0)
        return result;
    result = (int)func_0218A878(&input, gameSystem, fieldMap);
    if (result != 0)
        return result;
    result = func_0218B208(&input, gameSystem, fieldMap);
    if (result != 0)
        return result;

    blockFlags = 0;
    if ((int)func_020142E8((void *)func_0201296C(input.gameData), (u32)0x964) == 1)
        blockFlags |= 1;
    result = func_021A2F20(input.player, input.keyTrg, input.keyCont, blockFlags);
    if (result != 0)
        return result;

    gameComm = (void *)func_02012138(gameSystem);
    commWork = (void *)func_02158344((int)gameComm);
    playerMmdl = func_021A3074(input.player);
    if (func_0217BFD8((const void *)gameSystem, input.zoneId) == 1)
        return func_0217CA84(gameSystem, 0);
    if ((int)func_02026454(gameComm) == 2 && commWork != 0) {
        if (func_02012B70(input.gameData) == 1 && func_0217C070(commWork) == 1)
            return (int)func_0217B810(gameSystem, fieldMap);
        if (func_0217689C(commWork, input.zoneId) == 1)
            return (int)func_0216B3A8((int)gameSystem, 9, (u32)func_02012FB0(input.gameData));
        if (input.inputEnabled == 1 && func_021754B4(commWork, (int *)(&commTarget)) == 1) {
            func_021A2F6C(input.player);
            return (int)func_0217FC6C(gameSystem, (int)fieldMap, (int)commWork, (int)playerMmdl, commTarget, input.heapId);
        }
        if (input.stepDone) {
            result = func_0217BDE0((int)gameSystem, commWork, input.player);
            if (result != 0)
                return result;
        }
        if (input.aPressed && func_0217AFC4(commWork, input.player, (int *)(&commTarget)) == 1) {
            func_021A2F6C(input.player);
            return (int)func_0217FB5C(gameSystem, (int)fieldMap, (int)commWork, (int)playerMmdl, commTarget, input.heapId);
        }
    }

    if (input.aPressed) {
        u32 facing = func_021A3050(input.player);
        int frontMmdl;
        u32 scriptId;
        int gridX;
        int gridY;
        int gridZ;
        void *mapper;

        func_021A3038(input.player, (VecFx32 *)frontPos);
        func_02164208((u32)facing, frontPos, 0x10000);
        frontMmdl = func_0218B4B0(&input, fieldMap);
        if (frontMmdl != 0) {
            u32 eventId = func_0216D5B8((void *)frontMmdl);

            if (func_02158D90(eventId) == 1) {
                void *mmdl = func_021A3074(input.player);

                func_021A2F6C(input.player);
                *outResetEncount = 1;
                return func_0219F01C((u32)gameSystem, (u32)fieldMap, eventId, (u32)mmdl, frontMmdl, input.heapId);
            }
        }
        scriptId = func_02162A54(input.eventData, (void *)func_0201296C(input.gameData), frontPos, facing);
        if (scriptId != 0xFFFF)
            return (int)func_02158768((int)gameSystem, scriptId, 0, input.heapId);
        scriptId = func_0218B56C(&input, fieldMap);
        if (scriptId != 0xFFFF)
            return (int)func_02158768((int)gameSystem, scriptId, 0, input.heapId);
        gridX = frontPos[0] >> 12;
        gridY = frontPos[1] >> 12;
        gridZ = frontPos[2] >> 12;
        mapper = func_0200BE48(func_02012EBC(input.gameData));
        scriptId = (u32)func_021CFAC0(mapper, (u16)func_02188C9C(fieldMap), (s16)(gridX / 16), (s16)(gridY / 16), (s16)(gridZ / 16));
        if (scriptId != 0xFF)
            return (int)func_021CFC14(gameSystem, input.heapId, (void *)scriptId);
        if (func_021CD440(fieldMap, &areaZoneId) == 1)
            return (int)func_02158768((int)gameSystem, 0x271B, 0, input.heapId);
        if (func_02013FFC(input.zoneId)) {
            scriptId = func_02162940(input.eventData, (void *)func_0201296C(input.gameData), (int)frontPos);
            if (scriptId != 0xFFFF)
                return (int)func_02158768((int)gameSystem, scriptId, 0, input.heapId);
        }
    }

    if (input.moveState == 3 || input.moveState == 0) {
        result = func_0218B408(&input, gameSystem, fieldMap);
        if (result != 0)
            return result;
    }
    if (input.pushingFacing) {
        result = func_0218AED4(&input, (int)gameSystem, fieldMap);
        if (result != 0)
            return result;
        result = func_0218AF90(&input, gameSystem, fieldMap);
        if (result != 0)
            return result;
    }
    if (input.yPressed && func_020221A4()) {
        void *subscreen = (void *)func_02188CCC(fieldMap);

        if (func_0215FF34(gameSystem) && func_021A0ED4((u32)subscreen)) {
            result = (int)func_0215FF54((int)gameSystem, (int)fieldMap, input.heapId);
            if (result != 0)
                return result;
        }
    }
    if (func_0201212C(gameSystem) == 1 && func_020221A4() && input.inputEnabled)
        return func_021C06CC(gameSystem, fieldMap);
    if (input.xPressed && func_020221A4()) {
        if ((int)func_021A0F90((void *)func_02188CCC(fieldMap)) == 6)
            return 0;
        *outMenuRequest = 1;
        return (int)func_0215FC40((int)gameSystem, (int)fieldMap, input.heapId);
    }
    if (func_020221A4()) {
        result = func_021A0EB0((void *)func_02188CCC(fieldMap), input.noButton);
        if (result != 0)
            return result;
    }
    if (input.noButton && func_020221A4()) {
        result = (int)func_0218ACA8(gameSystem);
        if (result != 0)
            return result;
    }
    result = func_0217B410((int)fieldMap, (int)gameSystem, input.player);
    if (result == 0)
        return 0;
    return result;
}


int func_0218A074(void *gameSystem, FieldMap *fieldMap)
{
    int resetEncount;
    int menuRequest;
    int result;
    FieldMap *curFieldMap;
    void *encount;

    curFieldMap = func_0201210C(gameSystem);
    encount = (void *)func_02188CE8(curFieldMap);
    func_021AA8F8();
    result = func_02189BD0(gameSystem, fieldMap, &resetEncount, &menuRequest);
    if (result != 0) {
        if (resetEncount != 0)
            func_021AA8EC(encount);
        func_021BC5BC((u8 *)((void *)func_02188D20(curFieldMap)));
        func_021A3550(func_02188CB4(curFieldMap), menuRequest);
        func_021A356C(func_02188CB4(curFieldMap));
        if (func_02189A70(curFieldMap) != 0)
            func_021F3B10();
        func_0218A6E8(gameSystem, curFieldMap);
    }
    return result;
}


int func_0218A0E4(void *gameSystem, FieldMap *fieldMap)
{
    FieldEventInput input;
    void *gameComm;
    void *commWork;
    int result;
    int frontMmdl;
    u32 eventId;
    void *playerMmdl;

    gameComm = (void *)func_02012138(gameSystem);
    commWork = (void *)func_02026474(gameComm);
    func_0218A4E0(&input, gameSystem, fieldMap);
    if (commWork == 0) {
        if (func_0200FB24() != 0) {
            if (func_020221A4() != 0)
                return func_021C06CC(gameSystem, fieldMap);
            return 0;
        }
        return (int)func_021850FC(gameSystem, fieldMap);
    }
    if (func_0217391C(commWork) == 1) {
        if (func_02173928(commWork) == 0)
            func_02026400(gameComm);
        return 0;
    }
    if (input.walkStepDone && (result = func_0218A784(&input, 9)) != 0)
        return result;
    if ((result = func_0217B80C((int)gameSystem, (int)fieldMap)) != 0)
        return result;
    if (input.aPressed && (result = func_0217B83C(gameSystem, fieldMap)) != 0)
        return result;
    if (input.aPressed && func_0217394C(gameSystem) == 1) {
        frontMmdl = func_0218B4B0(&input, fieldMap);
        if (frontMmdl != 0) {
            eventId = func_0216D5B8((void *)frontMmdl);
            if (func_02158D90(eventId) == 1) {
                playerMmdl = func_021A3074(input.player);
                if (func_0217AF38(func_0216D588((void *)frontMmdl)) == 0) {
                    func_021A2F6C(input.player);
                    return func_0219F01C((u32)gameSystem, (u32)fieldMap, eventId, (u32)playerMmdl, frontMmdl, input.heapId);
                }
            }
        }
    }
    if (func_0201212C(gameSystem) == 1 && func_020221A4() != 0)
        return func_021C06CC(gameSystem, fieldMap);
    if (func_0217394C(gameSystem) == 0)
        return 0;
    if (input.xPressed && func_020221A4() != 0)
        return func_0215FCE0((int)gameSystem, (int)fieldMap, input.heapId);
    return 0;
}


int func_0218A240(void *gameSystem, FieldMap *fieldMap)
{
    FieldMap *curFieldMap;
    int result = func_0218A278(gameSystem, fieldMap);
    if (result != 0) {
        curFieldMap = func_0201210C(gameSystem);
        func_021BC5BC((u8 *)func_02188D20(curFieldMap));
        if (func_02189A70(curFieldMap) != 0)
            func_021F3B10();
        func_0218A6E8(gameSystem, curFieldMap);
    }
    return result;
}


int func_0218A278(void *gameSystem, FieldMap *fieldMap)
{
    FieldEventInput input;
    RailLocation frontLocation;
    RailLocation nextLocation;
    RailLocation locationCopy;
    void *playerMmdl;
    int result;
    u32 scriptId;

    func_0218A4E0(&input, gameSystem, fieldMap);
    playerMmdl = func_021A3074(input.player);
    func_0219E634(playerMmdl, &frontLocation);
    result = func_0218A738(&input);
    if (result != 0)
        return result;
    if (input.walkStepDone)
        func_0218A728(input.gameData);
    if (input.walkStepDone) {
        void *playerMmdlNow = func_021A3074(input.player);
        void *eventWork = (void *)func_0201296C(input.gameData);

        func_0219E2F4(playerMmdlNow, &nextLocation);
        scriptId = func_02162958(input.eventData, eventWork, &nextLocation);
        if (scriptId != 0xFFFF)
            return (int)func_02158768((int)gameSystem, scriptId, 0, input.heapId);
        result = func_0218B0CC(&input, gameSystem, fieldMap);
        if (result != 0)
            return result;
        result = func_0218A9B0(&input, fieldMap);
        if (result != 0)
            return result;
    }
    result = func_0218B208(&input, gameSystem, fieldMap);
    if (result != 0)
        return result;
    if (input.aPressed) {
        int frontMmdl = func_0218B53C(&input, fieldMap);
        void *eventWork;
        u16 dirDisp;

        if (frontMmdl != 0) {
            u32 eventId = func_0216D5B8((void *)frontMmdl);

            if (func_02158D90(eventId) == 1) {
                void *mmdl = func_021A3074(input.player);

                func_021A2F6C(input.player);
                return func_0219F01C((u32)gameSystem, (u32)fieldMap, eventId, (u32)mmdl, frontMmdl, input.heapId);
            }
        }
        eventWork = (void *)func_0201296C(input.gameData);
        dirDisp = func_0216D5F8(playerMmdl);
        locationCopy = frontLocation;
        scriptId = func_02162A5C(input.eventData, eventWork, &locationCopy, dirDisp);
        if (scriptId != 0xFFFF)
            return (int)func_02158768((int)gameSystem, scriptId, 0, input.heapId);
    }
    if (input.pushingFacing && func_0218B310(func_02188CB4(fieldMap), &input) == 0) {
        result = func_0218B13C(&input, gameSystem, fieldMap, &frontLocation);
        if (result != 0)
            return result;
    }
    result = func_0218B24C(&input, gameSystem, fieldMap);
    if (result != 0)
        return result;
    if (input.yPressed && func_020221A4()) {
        void *subscreen = (void *)func_02188CCC(fieldMap);

        if (func_0215FF34(gameSystem) && func_021A0ED4((u32)subscreen)) {
            result = (int)func_0215FF54((int)gameSystem, (int)fieldMap, input.heapId);
            if (result != 0)
                return result;
        }
    }
    if (func_0201212C(gameSystem) == 1 && func_020221A4() && input.inputEnabled)
        return func_021C06CC(gameSystem, fieldMap);
    if (input.xPressed && func_020221A4()) {
        if (func_021A0F90((void *)func_02188CCC(fieldMap)) == 6)
            return 0;
        return (int)func_0215FC40((int)gameSystem, (int)fieldMap, input.heapId);
    }
    {
        u32 noButtonActive = (input.noButton && func_020221A4()) ? 1 : 0;

        result = func_021A0EB0((void *)func_02188CCC(fieldMap), noButtonActive);
        if (result != 0)
            return result;
    }
    if (input.noButton && func_020221A4()) {
        result = (int)func_0218ACA8(gameSystem);
        if (result != 0)
            return result;
    }
    return 0;
}


int func_0218A4BC(void *gameSystem, FieldMap *fieldMap, u32 unusedC, u32 unusedD)
{
    if (func_02188CFC(fieldMap) == 0)
        return func_0218A074(gameSystem, fieldMap);
    return func_0218A240(gameSystem, fieldMap);
}


/*
 * Fills the 0x40 byte field input record for one frame: pad trigger and held
 * keys, the held d-pad direction, the player object's position, facing and
 * movement state, and the request bitfield at 0x3C (talk on A, menu on X,
 * registered item on Y, no-input, step, surf and push flags).
 */
void func_0218A4E0(FieldEventInput *input, void *gameSystem, FieldMap *fieldMap)
{
    void *playerMmdl;

    func_02082BCC(input, 0, 0x40);
    input->heapId = func_02188C84(fieldMap);
    input->gameSystem = gameSystem;
    input->gameData = func_020120F4(gameSystem);
    input->eventData = (void *)func_02012844(input->gameData);
    input->zoneId = func_02188C9C(fieldMap);
    input->keyTrg = func_020362DC();
    input->keyCont = func_0203630C();
    input->heldDir = 9;
    if (input->keyCont & 0x40)
        input->heldDir = 0;
    else if (input->keyCont & 0x80)
        input->heldDir = 1;
    else if (input->keyCont & 0x20)
        input->heldDir = 2;
    else if (input->keyCont & 0x10)
        input->heldDir = 3;
    input->fieldMap = fieldMap;
    input->player = func_02188CB4(fieldMap);
    func_021A2FE4(input->player);
    input->moveMode = func_021A3080(input->player);
    input->moveState = func_021A308C(input->player);
    playerMmdl = func_021A3074(input->player);
    input->facingDir = func_0216D5F8(playerMmdl);
    input->playerPos = (VecFx32 *)func_0216D888(playerMmdl);
    input->pendingScriptId = func_02014478(func_02012B38(input->gameData));
    input->tileAttr = func_021A30C8(input->player);

    if (input->moveState == 3 || input->moveState == 0) {
        u8 buttonCount;

        input->inputEnabled = 1;
        input->aPressed = (input->keyTrg & 1) ? 1 : 0;
        input->xPressed = (input->keyTrg & 0x400) ? 1 : 0;
        input->yPressed = (input->keyTrg & 0x800) ? 1 : 0;
        buttonCount = 0;
        buttonCount += input->aPressed;
        buttonCount += input->xPressed;
        buttonCount += input->yPressed;
        if (buttonCount == 0)
            input->noButton = 1;
    }
    input->walkStepDone = 0;
    input->tileChanged = 0;
    if (input->moveMode == 1)
        input->walkStepDone = (input->moveState == 3) ? 1 : 0;
    if (func_021A3584(input->player))
        input->tileChanged = 1;
    input->stepDone = (input->moveState == 3) ? 1 : 0;
    input->otherMoveBusy = 0;
    if (input->moveState != 3 && input->moveMode == 2)
        input->otherMoveBusy = 1;
    if ((input->facingDir == 0 && (input->keyCont & 0x40)) || (input->facingDir == 1 && (input->keyCont & 0x80))
        || (input->facingDir == 2 && (input->keyCont & 0x20)) || (input->facingDir == 3 && (input->keyCont & 0x10)))
        input->pushingFacing = 1;
    else
        input->pushingFacing = 0;
}


void func_0218A6E8(void *gameSystem, FieldMap *fieldMap)
{
    void *subscreenProc;

    subscreenProc = (void *)func_021A1358((u32 *)func_02188CCC(fieldMap));
    if (subscreenProc == 0) {
        func_02028A70((void *)func_02012A30(func_020120F4(gameSystem)));
        return;
    }
    if (func_021F2AB8(subscreenProc) == 0) {
        func_02028A70((void *)func_02012A30(func_020120F4(gameSystem)));
        func_021F2AD4(subscreenProc);
    }
}


int func_0218A728(void *gameData)
{
return func_02008DF0((void *)func_02012F2C((int *)gameData), 0);
}


/*
 * Starts the pending script (field 0x26) through func_02158768, or else asks
 * func_02158B00 for the default one; returns the result.
 */
int func_0218A738(FieldEventInput *input)
{
    int r;

    if (input->pendingScriptId != 0) {
        func_02014474(func_02012B38(input->gameData), 0);
        return (int)func_02158768((int)input->gameSystem, input->pendingScriptId, 0, input->heapId);
    }
    r = (int)func_02158B00(input->gameSystem, input->heapId);
    if (r == 0)
        return 0;
    return r;
}


/*
 * Tries func_0218A8BC, then func_0218A784 with direction 9.
 */
int func_0218A76C(FieldEventInput *input)
{
    int r = func_0218A8BC(input);

    if (r != 0)
        return r;
    return func_0218A784(input, 9);
}


/*
 * Unless the tile attribute under the object's position blocks it
 * (func_021AB188), asks ov010 func_02162928 for a message id and shows it
 * through func_02158768; returns 0 otherwise.
 */
int func_0218A784(FieldEventInput *input, int dir)
{
    FieldMap *curFieldMap = func_0201210C(input->gameSystem);
    void *eventWork = (void *)func_0201296C(input->gameData);
    u32 playerPos[3];
    u32 scriptId;

    func_021A3038(input->player, (VecFx32 *)playerPos);
    if (func_021AB188(func_021AB0F0(func_021AB0D4((void *)func_02188C98(curFieldMap), playerPos))) == 1)
        return 0;
    scriptId = func_02162928(input->eventData, eventWork, (int)playerPos, dir);
    if (scriptId != 0xFFFF)
        return (int)func_02158768((int)input->gameSystem, scriptId, 0, input->heapId);
    return 0;
}


/*
 * Tries func_0218A784 for the current facing, then for the direction from
 * func_021A2FA4 when that differs and is not 9.
 */
int func_0218A7F0(FieldEventInput *input)
{
    int result = func_0218A784(input, input->facingDir);
    int inputDir;

    if (result != 0)
        return result;
    inputDir = func_021A2FA4(input->player, input->keyCont);
    if (inputDir == 9 || inputDir == input->facingDir)
        return 0;
    result = func_0218A784(input, inputDir);
    if (result == 0)
        return 0;
    return result;
}


/*
 * Maps the held d-pad bits (up, down, left, right) to a direction and, unless
 * it is the current facing, none, or the movement mode is 1 or 2, tries
 * func_0218A784 with it. The two-value mode test is a switch.
 */
int func_0218A824(FieldEventInput *input)
{
    u32 keyCont = input->keyCont;
    u32 moveState = input->moveState;
    int heldDir = 9;

    if (keyCont & 0x40)
        heldDir = 0;
    else if (keyCont & 0x80)
        heldDir = 1;
    else if (keyCont & 0x20)
        heldDir = 2;
    else if (keyCont & 0x10)
        heldDir = 3;
    if (heldDir == input->facingDir)
        return 0;
    if (heldDir == 9)
        return 0;
    switch (moveState) {
    case 1:
    case 2:
        return 0;
    }
    return func_0218A784(input, heldDir);
}


/*
 * When flag field 0x10 is set and func_021A2FA4 does not report 9, forwards
 * the object to ov018 func_0217B4D8; returns 0 otherwise.
 */
void *func_0218A878(FieldEventInput *input, void *gameSystem, FieldMap *fieldMap)
{
    int inputDir;

    if (func_02013D5C(input->zoneId) == 0)
        return 0;
    inputDir = func_021A2FA4(input->player, input->keyCont);
    if (inputDir == 9)
        return 0;
    return func_0217B4D8(gameSystem, fieldMap, input->player, *(int * *)&input->playerPos, input->facingDir, inputDir);
}


/*
 * Checks the background event in front of the player: shows its message when
 * the player stands at the event's centre tile, or when the tile behaviour is
 * one of 0x58..0x5B or 0xA3..0xA6 (range test spelled as the add of the
 * complement,
 * docs/idioms/a-masked-byte-subtract-in-a-range-test-is-an-add-of-the-complement.md)
 * or func_021A3098 allows it.
 */
int func_0218A8BC(FieldEventInput *input)
{
    FieldMap *curFieldMap = func_0201210C(input->gameSystem);
    void *player = func_02188CB4(curFieldMap);
    int playerPos[3];
    PosEvent *posEvent;
    int canTrigger;
    u16 tileBehavior;
    u32 centerX;
    u16 *area;
    u32 centerZ;

    func_021A3038(player, (VecFx32 *)playerPos);
    if (func_021AB188(func_021AB0F0(func_021AB0D4((void *)func_02188C98(curFieldMap), playerPos))) != 1)
        return 0;
    posEvent = (PosEvent *)func_0216282C(input->eventData, (void *)func_0201296C(input->gameData), playerPos, 9);
    if (posEvent == 0)
        return 0;
    if (posEvent->posType != 0)
        return 0;
    area = (u16 *)&posEvent->area;
    centerZ = area[1] + ((u32)area[3] >> 1);
    centerX = posEvent->area.x + ((u32)area[2] >> 1);
    if (centerX == (playerPos[0] >> 12) / 16 && centerZ == (playerPos[2] >> 12) / 16)
        return (int)func_02158768((int)input->gameSystem, posEvent->scriptId, 0, input->heapId);
    canTrigger = func_021A3098(player);
    tileBehavior = func_0216D7C4(func_021A3074(player));
    if (canTrigger != 0 || tileBehavior == 0x58 || tileBehavior == 0x59 || tileBehavior == 0x5A || tileBehavior == 0x5B || (u16)(tileBehavior + 0xFF5D) <= 3)   /*
tileBehavior - 0xA3
 */
        return (int)func_02158768((int)input->gameSystem, posEvent->scriptId, 0, input->heapId);
    return 0;
}


/*
 * Field step handler: runs the step-triggered checks in order (func_0218AC84,
 * the 128-step counter, milestones, egg hatching, the save flag message) and
 * returns the first non-zero result. Flags come from the u32 bitfield at
 * 0x3C.
 */
int func_0218A9B0(FieldEventInput *input, FieldMap *fieldMap)
{
    void *gameSystem;
    void *gameData;
    int result;

    func_02188C84(fieldMap);
    gameSystem = func_02188C80(fieldMap);
    gameData = func_020120F4(gameSystem);
    if (input->walkStepDone || input->tileChanged) {
        result = func_0218AC84(fieldMap, gameSystem, gameData);
        if (result != 0)
            return result;
    }
    if (!input->walkStepDone)
        return 0;
    func_0218AB9C(input->gameData, fieldMap);
    result = func_0218AC08(gameSystem, fieldMap, input->zoneId);
    if (result != 0)
        return result;
    result = func_0218AB50(input, fieldMap, gameSystem, gameData);
    if (result != 0)
        return result;
    result = func_0218AC4C(fieldMap, gameSystem, gameData);
    if (result == 0)
        return 0;
    return result;
}


/*
 * Returns 2 when a non-egg party member holds item 0x31 or 0x28, else 1.
 */
int func_0218AA2C(void *party)
{
    int memberCount = func_0201AA18(party);
    int index;

    for (index = 0; index < memberCount; index++) {
        void *member = func_0201AB28(party, index);
        u32 heldItem = func_02017E1C(member, 0xA, 0);
        if (func_02017E1C(member, 0x4C, 0) == 0 && (heldItem == 0x31 || heldItem == 0x28))
            return 2;
    }
    return 1;
}


/*
 * For every egg in the party, lowers field 9 (the step counter) by the amount
 * from func_0218AA2C, clamping at zero.
 */
void func_0218AA74(void *party)
{
    int memberCount = func_0201AA18(party);
    u32 decrement = func_0218AA2C(party);
    int index;

    for (index = 0; index < memberCount; index++) {
        void *member = func_0201AB28(party, index);
        u32 isEgg = func_02017E1C(member, 0x4C, 0);
        u32 eggCycles = func_02017E1C(member, 9, 0);
        if (isEgg == 1) {
            u32 newCycles = 0;
            if (eggCycles >= decrement)
                newCycles = eggCycles - decrement;
            func_02017E40(member, 9, newCycles);
        }
    }
}


/*
 * Adds func_02010FF4(0x100) to the step accumulator in the save block; once
 * it passes 0x10000 it advances the party's egg counters (func_0218AA74) and
 * resets it.
 */
void func_0218AAD0(void *gameData, void *party)
{
    void *stepSave = func_02008854(func_02012EBC(gameData));
    u32 stepCounter;

    func_02008970(stepSave, &stepCounter);
    stepCounter += func_02010FF4(0x100);
    if (stepCounter > 0x10000) {
        func_0218AA74(party);
        stepCounter = 0;
    }
    func_0200896C(stepSave, stepCounter);
}


/*
 * Returns 1 when some egg in the party has field 9 (the step counter) at
 * zero.
 */
int func_0218AB0C(void *party)
{
    int memberCount = func_0201AA18(party);
    int index;

    for (index = 0; index < memberCount; index++) {
        void *member = func_0201AB28(party, index);
        u32 isEgg = func_02017E1C(member, 0x4C, 0);
        u32 eggCycles = func_02017E1C(member, 9, 0);
        if (isEgg == 1 && eggCycles == 0)
            return 1;
    }
    return 0;
}


/*
 * Step hook: updates func_021C3378, advances the party step counter
 * (func_0218AAD0) and, when an egg is ready (func_0218AB0C), shows message
 * 0x8CA.
 */
int func_0218AB50(FieldEventInput *input, FieldMap *fieldMap, void *gameSystem, void *gameData)
{
    u16 heapId = func_02188C84(fieldMap);
    void *party = func_02012934(gameData);

    func_021C3378(func_02188D50(fieldMap));
    func_0218AAD0(gameData, party);
    if (func_0218AB0C(party))
        return (int)func_02158768((int)gameSystem, 0x8CA, 0, heapId);
    return 0;
}


/*
 * Bumps a 7-bit counter in the save block; when it wraps, calls func_0201B7EC
 * on every party member with the two coordinates read from the position
 * object.
 */
void func_0218AB9C(void *gameData, FieldMap *fieldMap)
{
    void *walkSave = func_02008854(func_02012EBC(gameData));
    int counterWrapped = 0;
    u16 walkCount = func_02008978(walkSave) + 1;

    if (walkCount >= 0x80) {
        walkCount = 0;
        counterWrapped = 1;
    }
    func_02008980(walkSave, walkCount);
    if (counterWrapped) {
        void *party = func_02012934(gameData);
        int zoneId;
        int heapId;
        int memberCount;
        int index;

        zoneId = func_02188C9C(fieldMap);
        heapId = func_02188C84(fieldMap);
        memberCount = func_0201AA18(party);
        for (index = 0; index < memberCount; index++)
            func_0201B7EC(func_0201AB28(party, index), zoneId, heapId);
    }
}


/*
 * When func_02013FFC accepts the id, shows the milestone message
 * (func_021D220C) and increments the save block counter; returns the message
 * result.
 */
int func_0218AC08(void *gameSystem, FieldMap *fieldMap, u16 zoneId)
{
    void *stepSave = func_02008854(func_02012EBC(func_020120F4(gameSystem)));
    int result = 0;

    if (func_02013FFC(zoneId)) {
        result = func_021D220C(gameSystem, fieldMap);
        func_02008988(stepSave, func_02008990(stepSave) + 1);
    }
    return result;
}


int func_0218AC4C(FieldMap *fieldMap, void *gameSystem, void *gameData)
{
    if ((u8)func_0200D564(func_0200D418(func_02012EBC(gameData))))
        return (int)func_02158768((int)gameSystem, 0x2792, 0, func_02188C84(fieldMap));
    return 0;
}


/*
 * Runs func_021AA944 on the position's object; when it declines, calls
 * func_021AA80C and returns 0.
 */
int func_0218AC84(FieldMap *fieldMap, void *gameSystem, void *gameData)
{
    void *encount;
    int result;

    func_02012EBC(gameData);
    encount = (void *)func_02188CE8(fieldMap);
    result = func_021AA944(encount);
    if (result == 0) {
        func_021AA80C(encount);
        return 0;
    }
    return result;
}


struct GameEvent *func_0218ACA8(void *gameSystem)
{
    if (func_02010F18() == 0x30) {
        return 0;
    }
    return func_020124AC(gameSystem, (u32)abs_id_83, (u32 (*)(void *, u32))func_021F532C, 0);
}


/*
 * For a usable entry id (func_0218AE04), unless ov010 func_021626EC reports
 * kind 1 or func_0218AEAC rejects it, builds its record (func_0218ADC8) and
 * dispatches it (func_0218AD80).
 */
int func_0218ACD0(FieldEventInput *input, FieldMap *fieldMap, VecFx32 *pos)
{
    u32 connectId = func_0218AE04(input, pos);
    void *connect;

    if (connectId == 0xFFFF)
        return 0;
    connect = func_021625CC(input->eventData, (u16)connectId);
    if (func_021626EC(connect) == 1 || !func_0218AEAC(connect))
        return 0;
    func_0218ADC8(input, connectId, pos);
    return func_0218AD80(input, fieldMap, connectId, pos);
}


/*
 * Looks up the tile attribute under the position and starts the matching tile
 * task (func_021C8A30 or func_021C8C88); returns the task or 0.
 */
void *func_0218AD28(FieldEventInput *input, FieldMap *fieldMap)
{
    int playerVec[3];
    u16 tileAttr;

    func_021A3038(input->player, (VecFx32 *)playerVec);
    tileAttr = func_021AB0F0(func_021AB0D4((void *)func_02188C98(fieldMap), playerVec));
    if (func_021C8A74(tileAttr))
        return func_021C8A30(0, input->gameSystem, fieldMap);
    if (func_021C8CF0(tileAttr))
        return func_021C8C88(0, input->gameSystem, fieldMap);
    return 0;
}


/*
 * Looks up entry id through func_021625CC, optionally resolves its argument,
 * then dispatches to ov020 func_02185410 for kind 6 or func_02185360
 * otherwise.
 */
int func_0218AD80(FieldEventInput *input, FieldMap *fieldMap, int connectId, VecFx32 *pos)
{
    void *connect = func_021625CC(input->eventData, (u16)connectId);
    void *exitOffset;

    if (pos != 0)
        exitOffset = (void *)func_021626A8(connect, pos);
    else
        exitOffset = 0;
    if (func_021626E8(connect) == 6)
        return (int)func_02185410(input->gameSystem, (int)fieldMap, (int)connect, (int)exitOffset);
    else
        return (int)func_02185360(input->gameSystem, (int)fieldMap, (int)connect, (int)exitOffset);
}


/*
 * Builds a 0x1C byte rectangle record with func_02014110 from the object's
 * map value, an id and three words, and hands it to func_02012878.
 */
void func_0218ADC8(FieldEventInput *input, int connectId, VecFx32 *pos)
{
    u8 location[0x1C];

    func_02014110(location, func_02188C9C(input->fieldMap), connectId, 0, 0, pos->x, pos->y, pos->z);
    func_02012878(input->gameData, (const void *)location);
}


/*
 * Returns the current entry id from func_02162564 when it is usable
 * (func_0218AEAC or func_0218AECC accepts it), else 0xFFFF.
 */
u32 func_0218AE04(FieldEventInput *input, VecFx32 *pos)
{
    u32 connectId = (u32)func_02162564(input->eventData, pos);
    void *connect;

    if (connectId == 0xFFFF)
        return 0xFFFF;
    connect = func_021625CC(input->eventData, (u16)connectId);
    if (!func_0218AEAC(connect) && !func_0218AECC(connect, input->facingDir))
        return 0xFFFF;
    return connectId;
}


void func_0218AE48(FieldEventInput *input, VecFx32 *out)
{
    *out = *input->playerPos;
    switch (input->facingDir) {
    case 0:
        out->z -= 0x10000;
        break;
    case 1:
        out->z += 0x10000;
        break;
    case 2:
        out->x -= 0x10000;
        break;
    case 3:
        out->x += 0x10000;
        break;
    }
}


/*
 * True when func_021626E8 reports kind 0, 5 or 6.
 */
int func_0218AEAC(void *connect)
{
    u8 exitType = func_021626E8(connect);
    return exitType == 0 || exitType == 5 || exitType == 6;
}


int func_0218AECC(void *connect, int dir)
{
    return func_021626B8(connect, dir);
}


int func_0218AED4(FieldEventInput *input, int unused, FieldMap *fieldMap)
{
    VecFx32 frontPos;
    int connectId;
    void *connect;

    func_0218AE48(input, &frontPos);
    if ((func_021AB0F8(func_021AB0D4((void *)func_02188C98(fieldMap), &frontPos)) & 1) == 0)
        return 0;
    connectId = (int)func_0218AE04(input, input->playerPos);
    if (connectId != 0xFFFF) {
        connect = func_021625CC(input->eventData, (u16)connectId);
        if (func_021626EC(connect) == 0 && func_021626E8(connect) == 1) {
            func_0218ADC8(input, connectId, input->playerPos);
            return func_0218AD80(input, fieldMap, connectId, input->playerPos);
        }
    }
    connectId = (int)func_0218AE04(input, &frontPos);
    if (connectId != 0xFFFF) {
        if (func_021626EC(func_021625CC(input->eventData, (u16)connectId)) == 0) {
            func_0218ADC8(input, connectId, input->playerPos);
            return func_0218AD80(input, fieldMap, connectId, &frontPos);
        }
    }
    return 0;
}


int func_0218AF90(FieldEventInput *input, void *gameSystem, FieldMap *fieldMap)
{
    VecFx32 frontPos;
    VecFx32 aheadPos;
    int aheadHeight;
    u32 frontAttr;
    void *playerMmdl;

    func_0218AE48(input, &frontPos);
    if (func_021BE288(fieldMap, 6))
        return func_021F3A88((int)gameSystem, frontPos.x / 0x10000, frontPos.z / 0x10000);
    if (func_021BE288(fieldMap, 0x19) || func_021BE288(fieldMap, 0x1A) || func_021BE288(fieldMap, 0x1B))
        return func_021F38A4((int)fieldMap, input->facingDir);
    frontAttr = func_021AB0D4((void *)func_02188C98(fieldMap), &frontPos);
    if ((func_021AB0F8(frontAttr) & 1) == 0)
        return 0;
    if (func_021A3098(input->player) == 2 && func_0218B630(input->gameData, 0x7F) != 6
        && func_021AB310(func_021AB0F0(frontAttr)) == 1) {
        aheadPos = frontPos;
        playerMmdl = func_021A3074(input->player);
        func_02164208(input->facingDir, (int *)(&aheadPos), 0x10000);
        if (func_02163E58(playerMmdl, &aheadPos, &aheadHeight) == 1 && frontPos.y > aheadHeight)
            return (int)func_02158768((int)input->gameSystem, 0x271F, 0, input->heapId);
    }
    if (func_0218AE04(input, &frontPos) == 0xFFFF) {
        if (func_021BE288(fieldMap, 2))
            return func_021F404C(gameSystem);
        if (func_021BE288(fieldMap, 5))
            return func_021F37E0(gameSystem);
    }
    return 0;
}


int func_0218B0CC(FieldEventInput *input, void *unused, FieldMap *fieldMap)
{
    RailLocation nextLocation;
    int connectId;
    void *connect;

    func_0219E2F4(func_021A3074(func_02188CB4(fieldMap)), &nextLocation);
    connectId = func_02162598(input->eventData, &nextLocation);
    if (connectId == 0xFFFF)
        return 0;
    connect = func_021625CC(input->eventData, (u16)connectId);
    if (func_021626EC(connect) == 1 || func_0218AEAC(connect) == 0)
        return 0;
    func_0218B2A8(input, connectId, &nextLocation);
    return func_0218B2E8(input, fieldMap, connectId, &nextLocation);
}


int func_0218B13C(FieldEventInput *input, void *unused, FieldMap *fieldMap, RailLocation *frontLocation)
{
    RailLocation nextLocation;
    int connectId;
    void *connect;

    func_0219E2F4(func_021A3074(func_02188CB4(fieldMap)), &nextLocation);
    connectId = func_02162598(input->eventData, &nextLocation);
    if (connectId != 0xFFFF) {
        connect = func_021625CC(input->eventData, (u16)connectId);
        if (func_021626EC(connect) == 0 && func_0218AECC(connect, input->facingDir) != 0
            && func_021626E8(connect) == 1) {
            func_0218B2A8(input, connectId, &nextLocation);
            return func_0218B2E8(input, fieldMap, connectId, &nextLocation);
        }
    }
    connectId = func_02162598(input->eventData, frontLocation);
    if (connectId == 0xFFFF)
        return 0;
    connect = func_021625CC(input->eventData, (u16)connectId);
    if (func_021626EC(connect) == 0 && func_0218AECC(connect, input->facingDir) != 0) {
        func_0218B2A8(input, connectId, &nextLocation);
        return func_0218B2E8(input, fieldMap, connectId, &nextLocation);
    }
    return 0;
}


/*
 * When bit 3 of the flag word is set, runs the object's interaction:
 * func_021AA248 with the map value when func_02013DD0 accepts field 0x10,
 * else func_021A9F40(obj, 0).
 */
int func_0218B208(FieldEventInput *input, void *unused, FieldMap *fieldMap)
{
    void *encount = (void *)func_02188CE8(fieldMap);

    if (!input->stepDone)
        return 0;
    if (func_02013DD0(input->zoneId))
        return func_021AA248(encount, func_0218DC70((u8 *)func_02188C98(fieldMap)));
    return func_021A9F40(encount, 0);
}


int func_0218B24C(FieldEventInput *input, void *gameSystem, FieldMap *fieldMap)
{
    void *player = func_02188CB4(fieldMap);
    void *playerMmdl = func_021A3074(player);
    int inputDir = func_021A2FA4(player, input->keyCont);

    if (inputDir == 1) {
        int moveState = input->moveState;
        if (moveState == 0 || moveState == 3) {
            if (func_021BB188(func_021AB0F0(input->tileAttr))) {
                if (func_0219E418((u32)playerMmdl, inputDir) & 3)
                    return func_021C46F8((u32)gameSystem, (u32)fieldMap, inputDir);
            }
        }
    }
    return 0;
}


void func_0218B2A8(FieldEventInput *input, int connectId, RailLocation *location)
{
    u8 locationRec[0x1C];

    func_02014134(locationRec, func_02188C9C(input->fieldMap), (s16)connectId, 0, 0, location->railIndex, location->lineGrid, location->widthGrid);
    func_02012878(input->gameData, (const void *)locationRec);
}


int func_0218B2E8(FieldEventInput *input, FieldMap *fieldMap, int connectId, RailLocation *location)
{
    void *connect = func_021625CC(input->eventData, (u16)connectId);
    return (int)func_02185360(input->gameSystem, (int)fieldMap, (int)connect, func_021626B0(connect, location));
}


int func_0218B310(void *player, FieldEventInput *input)
{
    if ((func_0219E418((u32)func_021A3074(player), input->facingDir) & 3) == 0)
        return 1;
    return 0;
}


int func_0218B32C(void *task, int *seq, LedgeJumpWork *work)
{
    void *player = func_02188CB4(work->fieldMap);
    void *playerMmdl;
    int acmdCode;

    func_021A3098(player);
    playerMmdl = func_021A3074(player);
    switch (*seq) {
    case 0:
        func_0216D9A0(func_0216D67C(playerMmdl));
        func_0216D5E0((int)playerMmdl, work->dir);
        *seq = *seq + 1;
        break;
    case 1:
        func_021ACBB8((u32)func_021A2F98(player), 0);
        func_021A2F48(player, 1);
        func_021A2F60(player);
        acmdCode = func_02197E7C(work->dir, 0x34);
        if (work->jumpTwoTiles == 1)
            acmdCode = func_02197E7C(work->dir, 0x38);
        func_0216D410(playerMmdl, acmdCode);
        *seq = *seq + 1;
        break;
    case 2:
        if (func_0216D454(playerMmdl) == 1) {
            func_021A2FD0(player);
            *seq = *seq + 1;
        }
        break;
    case 3:
        func_0216D9E4(func_0216D67C(playerMmdl));
        func_021A35A0(player, 1);
        return 1;
    }
    return 0;
}


int func_0218B3DC(int unused, void *gameSystem, FieldMap *fieldMap, int dir, int jumpTwoTiles)
{
    int h = (int)func_020122C0((void *)gameSystem, 0, func_0218B32C, 0x10);
    LedgeJumpWork *work = func_020124E8((void *)h);
    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->dir = dir;
    work->jumpTwoTiles = jumpTwoTiles;
    return h;
}


int func_0218B408(FieldEventInput *input, void *gameSystem, FieldMap *fieldMap)
{
    void *g3dMapper;
    int inputDir;
    int frontTile;
    int jumpTwoTiles;
    int frontAttr;
    void *player;
    int frontHitBits;
    int frontPos[3];

    player = func_02188CB4(fieldMap);
    if (func_021A3098(player) == 2) {
        g3dMapper = (void *)func_02188C98(fieldMap);
        inputDir = func_021A2FA4((u8 *)(*(int *)&input->player), input->keyCont);
        if (inputDir != 9) {
            func_021A3364(player, inputDir, frontPos);
            frontTile = func_021AB0D4(g3dMapper, frontPos);
            frontHitBits = func_021AB0F8(frontTile);
            frontAttr = func_021AB0F0(frontTile);
            jumpTwoTiles = 0;
            if (func_021AB2E8(frontAttr) == 1) {
                func_02164208(inputDir, frontPos, 0x10000);
                frontHitBits = func_021AB0F8(func_021AB0D4(g3dMapper, frontPos));
                jumpTwoTiles = 1;
            }
            if (func_0218B6F8(input, fieldMap) == 1 && !(frontHitBits & 1) && !(frontHitBits & 2))
                return func_0218B3DC((int)input, gameSystem, fieldMap, inputDir, jumpTwoTiles);
        }
    }
    return 0;
}


/*
 * Reads the object's grid position, and when the tile attribute in front
 * allows it (func_021AB194) steps it one tile in its facing direction, then
 * moves the camera object there (func_0216DDDC).
 */
int func_0218B4B0(FieldEventInput *input, FieldMap *fieldMap)
{
    void *playerMmdl = func_021A3074(input->player);
    s16 gridPos[3];
    int worldPos[3];
    void *mmdlSys;

    func_021A3460((u32)input->player, (u32)(&gridPos[2]), (u32)(&gridPos[1]), (u32)(&gridPos[0]));
    func_02164294(gridPos[2], gridPos[1], gridPos[0], worldPos);
    if (func_021AB194(func_021AB0F0(func_021AB0D4((void *)func_02188C98(fieldMap), worldPos))) == 1)
        func_02164240(func_0216D5F8(playerMmdl), &gridPos[2], &gridPos[0], 1);
    mmdlSys = func_02188C7C(fieldMap);
    return (int)func_0216DDDC((u32)mmdlSys, gridPos[2], gridPos[0], func_0216D8AC(playerMmdl), 0x10000, 0);
}


int func_0218B53C(FieldEventInput *input, FieldMap *fieldMap)
{
    RailLocation frontLocation;
    if (func_0219E634(func_021A3074(input->player), &frontLocation) != 0)
        return func_0219E570((u32)func_02188C7C(fieldMap), (u32)&frontLocation, 0);
    return 0;
}


/*
 * Picks the message for the tile the player faces: the first of the 13 table
 * entries at 0x021D3CE8 whose direction matches and whose attribute test
 * passes, else the water prompts 0x2712 (when a party member knows Surf) or
 * 0x2716; 0xFFFF for none.
 */
u16 func_0218B56C(FieldEventInput *input, FieldMap *fieldMap)
{
    u32 tileAttrHere;
    u32 tileAttrAhead;
    u16 aheadBehavior;
    u32 index;

    if (func_02012B70(input->gameData) == 1)
        return 0xFFFF;
    tileAttrHere = func_021A30C8(input->player);
    tileAttrAhead = func_021A3128(input->player, input->facingDir);
    aheadBehavior = func_021AB0F0(tileAttrAhead);
    for (index = 0; index < 13; index++) {
        if ((input->facingDir == data_021D3CE8[index].dir || data_021D3CE8[index].dir == 9) && data_021D3CE8[index].test(aheadBehavior))
            return data_021D3CE8[index].scriptId;
    }
    if (!func_02013E04(input->zoneId) || func_02012B70(input->gameData) == 1)
        return 0xFFFF;
    if (func_021A3504(input->player, tileAttrHere, tileAttrAhead) && func_0218B630(input->gameData, 0x39) != 6)
        return 0x2712;
    if (func_021A3524(input->player, (u32)tileAttrHere, (u32)tileAttrAhead))
        return 0x2716;
    return 0xFFFF;
}


/*
 * Returns the index of the first non-egg party member that knows the given
 * move (checks move slots 0x36..0x39), or 6 when none does. Called with 0x39
 * (Surf).
 */
int func_0218B630(void *gameData, u32 move)
{
    int memberCount;
    void *party;
    int index;

    party = func_02012934(gameData);
    memberCount = func_0201AA18(party);

    for (index = 0; index < memberCount; index++) {
        void *member = func_0201AB28(party, index);

        if (func_02017E1C(member, 0x4C, 0) == 0) {
            if (move == func_02017E1C(member, 0x36, 0) || move == func_02017E1C(member, 0x37, 0)
                || move == func_02017E1C(member, 0x38, 0) || move == func_02017E1C(member, 0x39, 0))
                return index;
        }
    }
    return 6;
}


int func_0218B6AC(void *gameSystem)
{
    void *party;
    void *member;
    int memberCount;
    int index;
    int aliveCount;

    party = func_02012934(func_020120F4(gameSystem));
    memberCount = func_0201AA18(party);
    index = 0;
    aliveCount = 0;
    for (; index < memberCount; index++) {
        member = func_0201AB28(party, index);
        if (func_02017E1C(member, 0x4C, 0) == 0 && func_02017E1C(member, 0xA0, 0) != 0)
            aliveCount++;
    }
    return aliveCount;
}


int func_0218B6F8(FieldEventInput *input, FieldMap *fieldMap)
{
    void *playerMmdl = func_021A3074(input->player);
    u16 heldDir = input->heldDir;
    int gridX = func_0216D83C(playerMmdl);
    int gridZ = func_0216D86C(playerMmdl);
    int index;

    for (index = 0; index < 2; index++) {
        gridX = (s16)(gridX + func_021641E8(heldDir));
        gridZ = (s16)(gridZ + func_021641F8(heldDir));
        if (func_0216DDC0((u32)func_02188C7C(fieldMap), gridX, gridZ, 1))
            return 0;
    }
    return 1;
}
