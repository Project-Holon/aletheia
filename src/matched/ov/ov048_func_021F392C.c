/*
 * function: FIELD_GIMMICK_GATE_LoadBoardRecord
 * address:  0x021F392C
 * packet:   pkt_ov048_021F392C
 * region:   ov048
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   ARC_TOOL_GetArchiveFileCount  0x02049030  arm
 *   GPOWER_GetSpecialPowerId  0x020111E8  thumb
 *   GIMMICK_OBJ_ELBOARD_ReadGateInfo  0x021F4C10  thumb  ov048
 *   gGateSourceFileName     0x021F5224  data  ov048  a1
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Rec {
    u32 a;
    u32 b;
    u32 pad[29];
} Rec;

typedef struct Obj {
    u16 f00;
    u32 f04;
    u32 pad08[5];
    Rec *f1c;
} Obj;

extern const char gGateSourceFileName[];

typedef unsigned char  u8;
extern u16 FIELDMAP_GetZoneId(u8 *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 ARC_TOOL_GetArchiveFileCount(u32 id);
extern u32 GPOWER_GetSpecialPowerId(void);
extern int GIMMICK_OBJ_ELBOARD_ReadGateInfo(int a, int b, int c);

void FIELD_GIMMICK_GATE_LoadBoardRecord(Obj *o)
{
    u32 i;
    u32 n;
    u32 r5;
    Rec buf;

    if (o->f1c == 0) {
        r5 = FIELDMAP_GetZoneId((u8 *)o->f04);
        i = 0;
        o->f1c = func_02030734(o->f00, 0x7c, 0, gGateSourceFileName, 0x387);
        n = ARC_TOOL_GetArchiveFileCount(0xae);
        for (; i < n; i++) {
            GIMMICK_OBJ_ELBOARD_ReadGateInfo((int)(&buf), 0xae, i);
            if (buf.a == r5) {
                if (buf.b == 0 || buf.b == GPOWER_GetSpecialPowerId()) {
                    *o->f1c = buf;
                    return;
                }
            }
        }
    }
}
