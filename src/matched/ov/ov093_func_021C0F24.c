/*
 * function: BTL_SERVER_FLOW_ProcMultiHitDamage
 * address: 0x021C0F24
 * packet: pkt_ov093_021C0F24
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: full-word aggregate eighth slot and declarations in spill order.
 * budget: 3 one runs; both permitted scheduling variants consumed.
 * symbols:
 *   func_021C1144 0x021C1144 thumb ov093
 *   func_021C1154 0x021C1154 thumb ov093
 *   func_021C1164 0x021C1164 thumb ov093
 *   PMS_SELECT_GRAPHIC_FlushRowWindow 0x021C1174 thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_MAIN_CheckSceneOff 0x021B8590 thumb ov093
 *   BTL_POKEPARAM_GetMajorStatusIndex 0x021D62A8 thumb ov093
 *   BTL_POKEPARAM_IsFainted 0x021D5B68 thumb ov093
 *   BTL_SERVER_CMD_Push 0x021CD4B0 thumb ov093
 *   BTL_SERVER_CMD_PushVariable 0x021CD64C thumb ov093
 *   BTL_SERVER_FLOW_BuildDamageList 0x021C0A4C thumb ov093
 *   BTL_SERVER_FLOW_ProcDamageRecordIfAny 0x021C11A4 thumb ov093
 *   BTL_SERVER_FLOW_ProcDamagedItemReaction 0x021C195C thumb ov093
 *   BTL_SERVER_FLOW_RollMoveAccuracy 0x021BFA60 thumb ov093
 *   BTL_SERVER_FLOW_PushEffectivenessMessage 0x021C15AC thumb ov093
 *
 * Single dynamic executor loop: 0FD4..10B8. Sum/counters retain full-word
 * wrapping adds and unsigned bound comparison; bound is reread after calls.
 * Both flag stores 0FF0/0FF8 precede executor calls. Own C091C proves
 * u32 return/fifth argument. C1144 targets matched ov095 CC70 u32 iterator;
 * 1154/1164/1174 target matched D5C8 (u8 key/result). Own C0A4C/C11A4
 * prove seven/eight physical slots, including 1000 and explicit final zero.
 * C15AC primary 15AC..15CE compares full signed r1 without truncation.
 * Flags is exactly one u32 with no padding, initialized by f.word=0.
 * Original 0FA4/0FA6 copies the initialized index-zero to sp28; 1048/104A
 * writes that full word to outgoing sp0C. Own C11A4 copies all 32 bits of
 * its eighth input unchanged into C11F0's eighth slot; scalar/aggregate
 * spelling changes neither bits nor arity. Run02/03 retain identical
 * physical argument stores, with only the five spill offsets corrected.
 */
#include "../include/Obj02134.h"
#include "../include/Obj21074.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct State { u8 pad[5]; u8 a:1; u8 b:1; };
struct Flags { u32 word; };
struct Entry { u16 value; u16 id:5, mode:4, type:4, marked:1, special:1, error:1; };
struct List { u8 good, bad, count, pad; struct Entry entries[1]; };
struct Q { u16 h0; u8 pad[6]; u32 w8; };
struct Slot { u32 a:3; u32 rest:29; };
struct Unk021D62A8 { u8 pad[0x1c]; struct Slot e[6]; };
extern u32 func_021C1144(void *, u32);
extern u8 func_021C1154(u8 *, u8);
extern u8 func_021C1164(u8 *, u8);
extern u8 PMS_SELECT_GRAPHIC_FlushRowWindow(u8 *, u8);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern unsigned int BTL_MAIN_CheckSceneOff(unsigned char *p);
extern int BTL_POKEPARAM_GetMajorStatusIndex(struct Unk021D62A8 *);
extern int BTL_POKEPARAM_IsFainted(void *);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
extern void BTL_SERVER_CMD_PushVariable(void *, u8, ...);
extern void BTL_SERVER_FLOW_BuildDamageList(u8 *, u8 *, u8 *, const u8 *, const u32 *, u16, struct List *);
extern u32 BTL_SERVER_FLOW_ProcDamageRecordIfAny(u8 *, u32, u32, u32, u8 *, u32, u32, struct Flags);
extern void BTL_SERVER_FLOW_ProcDamagedItemReaction(u8 *p, u8 *q, u32 n);
extern int BTL_SERVER_FLOW_RollMoveAccuracy(u8 *, u8 *, u8 *, struct Q *);
extern void BTL_SERVER_FLOW_PushEffectivenessMessage(u8 *, int);

u32 BTL_SERVER_FLOW_ProcMultiHitDamage(u8 *p, u8 *q, u8 *a, u8 *d, u32 c)
{
    u32 i;
    u32 completed;
    u32 sum = 0;
    int old;
    u8 tag = 6;
    u8 *b = (u8 *)func_021C1144(d, 0);
    struct State *s;
    struct Flags f;
    p[0x789] = BTL_POKEPARAM_GetPokeId(b);
    if (BTL_MAIN_CheckSceneOff(((struct Obj02134 *)p)->f4)) {
        tag = func_021C1154(p + 0x1ab8, BTL_POKEPARAM_GetPokeId(b));
        if (tag != 6) {
            BTL_SERVER_CMD_Push(((struct Obj02134 *)p)->fC, 0x4e,
                func_021C1164(p + 0x1ab8, BTL_POKEPARAM_GetPokeId(a)), tag, 0x27e);
        }
    }
    i = 0;
    completed = 0;
    f.word = 0;
    for (; i < (*(u8 **)(p + 0x4b4))[0]; i++) {
        old = BTL_POKEPARAM_GetMajorStatusIndex((struct Unk021D62A8 *)a);
        s = *(struct State * *)&((struct Obj02134 *)p)->f4A8;
        if (s->a == 0) {
            s->a = 1;
            s->b = 1;
        }
        BTL_SERVER_CMD_Push(((struct Obj02134 *)p)->fC, 0x30,
            (*(u8 **)(p + 0x4a8))[2], (*(u8 **)(p + 0x4a8))[3], ((struct Obj21074 *)q)->f0, 0);
        BTL_SERVER_FLOW_BuildDamageList(p, a, d, q, (const u32 *)c, 0x1000, *(struct List * *)&((struct Obj02134 *)p)->f870);
        sum += BTL_SERVER_FLOW_ProcDamageRecordIfAny(p, (u32)q, (u32)a, (u32)d,
            *(u8 * *)&((struct Obj02134 *)p)->f870, ((struct Obj02134 *)p)->f4B4, 0x1000, f);
        completed++;
        if (BTL_POKEPARAM_IsFainted(b)) break;
        if (BTL_POKEPARAM_IsFainted(a)) break;
        BTL_SERVER_FLOW_ProcDamagedItemReaction(p, b, 1);
        if (BTL_POKEPARAM_GetMajorStatusIndex((struct Unk021D62A8 *)a) == 2 && old != 2) break;
        if ((*(u8 **)(p + 0x4b4))[2] != 0 &&
            !BTL_SERVER_FLOW_RollMoveAccuracy(p, a, b, (struct Q *)q)) break;
    }
    if (completed != 0) {
        BTL_SERVER_FLOW_PushEffectivenessMessage(p, (*(u8 **)(p + 0x4b4))[5]);
        BTL_SERVER_CMD_PushVariable(((struct Obj02134 *)p)->fC, 0x5a, 0x20, completed, 0xffff0000);
    }
    if (BTL_POKEPARAM_IsFainted(b)) {
        BTL_SERVER_CMD_PushVariable(((struct Obj02134 *)p)->fC, 0x5b, 0, BTL_POKEPARAM_GetPokeId(b), 0xffff0000);
    }
    if (tag != 6) {
        BTL_SERVER_CMD_Push(((struct Obj02134 *)p)->fC, 0x4d,
            PMS_SELECT_GRAPHIC_FlushRowWindow(p + 0x1ab8, BTL_POKEPARAM_GetPokeId(a)), 0x291);
    }
    p[0x789] = 0x1f;
    return sum;
}
