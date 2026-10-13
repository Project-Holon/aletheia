/*
 * function: GIMMICK_OBJ_ELBOARD_AddSavedIdsMessage
 * address:  0x021F4314
 * packet:   pkt_ov048_021F4314
 * region:   ov048
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GIMMICK_OBJ_ELBOARD_GetHeapId  0x021F47B4  thumb  ov048
 *   func_0201EC64  0x0201EC64  thumb
 *   FIELD_GIMMICK_GATE_IsExtraSaveListOn  0x021F3AB4  thumb  ov048
 *   FIELD_GIMMICK_GATE_ReadExtraSaveValues  0x021F3AD4  thumb  ov048
 *   FIELD_GIMMICK_GATE_ReadSaveBlockValues  0x021F3B64  thumb  ov048
 *   func_0201EE60  0x0201EE60  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   GIMMICK_OBJ_ELBOARD_AddMessage  0x021F3D38  thumb  ov048
 *   func_0201ED04  0x0201ED04  thumb
 *   d_021F50C0     0x021F50C0  data  a4
 */

#include "../include/G_T.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int GIMMICK_OBJ_ELBOARD_GetHeapId(void *p);
struct WordSet;
extern struct WordSet *func_0201EC64(u32 heap);
extern int FIELD_GIMMICK_GATE_IsExtraSaveListOn(void *p);
extern void FIELD_GIMMICK_GATE_ReadExtraSaveValues(const u16 *p, u32 *out, int *cnt);
extern void FIELD_GIMMICK_GATE_ReadSaveBlockValues(u16 *p, u32 *out, int *cnt);
extern void func_0201EE60(struct WordSet *p, u32 i, u16 v);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void GIMMICK_OBJ_ELBOARD_AddMessage(int *p, int unused, int b, int *c);
extern u32 func_0201ED04(struct WordSet *p);
extern struct T d_021F50C0;

void GIMMICK_OBJ_ELBOARD_AddSavedIdsMessage(int *p)
{
    struct { u16 a; int b, c, d, e, f, g; } s;
    u32 buf[6];
    int cnt;
    void *h;
    int i;
    int f;

    h = func_0201EC64(GIMMICK_OBJ_ELBOARD_GetHeapId((void *)p[5]));
    if (FIELD_GIMMICK_GATE_IsExtraSaveListOn(p))
        FIELD_GIMMICK_GATE_ReadExtraSaveValues((const u16 *)p, buf, &cnt);
    else
        FIELD_GIMMICK_GATE_ReadSaveBlockValues((u16 *)p, buf, &cnt);
    switch (cnt) {
    case 0: break;
    case 1: f = 0xcd; break;
    case 2: f = 0xce; break;
    case 3: f = 0xcf; break;
    case 4: f = 0xd0; break;
    case 5: f = 0xd1; break;
    case 6: f = 0xd2; break;
    }
    for (i = 0; i < cnt; i++)
        func_0201EE60(h, i, buf[i]);
    func_0201F02C(h, 6, GAME_DATA_GetMyStatus((void *)p[2]));
    s.a = *(u16 *)(((u8 *)&d_021F50C0) + 0xa);
    s.b = *(int *)(((u8 *)&d_021F50C0) + 0x38);
    s.c = *(int *)(((u8 *)&d_021F50C0) + 0x54);
    s.d = 2;
    s.e = 0x26;
    s.f = f;
    s.g = (int)h;
    GIMMICK_OBJ_ELBOARD_AddMessage(p, (int)&s, 9, 0);
    func_0201ED04(h);
}
