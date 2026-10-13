/*
 * file:     unit_068996C8.c
 * unit:     yes
 * function: func_068996C8, func_068996D4
 * address:  0x068996C8
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B9A40  0x021B9A40  thumb
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb
 *   BTL_SERVER_FLOW_IsPokeGroundedById  0x021C8234  thumb
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb
 *   BTL_POKEPARAM_HasType  0x021D5814  thumb
 *   BTL_EVENT_GetVar  0x021D775C  thumb
 *   BTLV_CORE_MakeSlotKind1Empty  0x021E89C0  thumb
 *   func_021E8A58  0x021E8A58  thumb
 *   data_0689D708 0x0689D708 data a4
 *   HAND_SIDE_GetStackCountByFactor  0x06898DE0  thumb
 */
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct { int v; } Id;

extern int HAND_SIDE_GetStackCountByFactor(int a, u32 b);
extern int BTL_EVENT_GetVar(int a);
extern int func_021B9A40(int a);
extern int BTL_SERVER_FLOW_IsPokeGroundedById(void *a, int b);
extern int BTL_SERVER_FLOW_GetPokeParam(void *a, int b);
extern int BTL_POKEPARAM_HasType(int a, int b);
extern void *BTL_SERVER_FLOW_AllocCmdRecord();
extern void BTL_SERVER_FLOW_CommitCmdRecord();
extern u32 func_021E8A58(void);
extern u32 BTLV_CORE_MakeSlotKind1Empty(void);
void *func_068996C8(u32 *p);
void func_068996D4(int a, void *p, int x);
extern unsigned char data_0689D708[];


/*
 * Unlabelled store-and-return follower after the 0x068996B8 veneer.
 */
void *func_068996C8(u32 *p)
{
    *p = 1;
    return data_0689D708;
}

static inline Id cmpid(int a, u32 b) { Id r; r.v = HAND_SIDE_GetStackCountByFactor(a, b); return r; }


/*
 * accepted 2026-10-05 by the user: the held form (see the notes below) is accepted as plausible original source.
 * review 2026-10-05: parked for the user. EXACT* in c99 and c, but only with the cmpid() inline that
 *   returns a one-field struct to open an 8-byte frame hole; this may be a stand-in.
 * note:     2026-10-05 wave P14 C3. Older draft (docs/notes/pkt_ov095_068996D4.c.txt) was DIFF 18/172.
 *           The 12-byte frame (str r0,[sp] with sub sp,#0xc) comes from a one-field struct returned by an
 *           inline wrapper around the DE0 compare call; plain t pointer and unsigned loop counter (blo).
 *           Literal 3 gives the same bytes as a local n. Wrapping the other calls in a struct (alloc, id) also fits.
 */
void func_068996D4(int a, void *p, int x)
{
    u8 v;
    u32 i;
    u8 *t;
    u32 *q;

    v = BTL_EVENT_GetVar(2);
    if (x == func_021B9A40(v) && BTL_SERVER_FLOW_IsPokeGroundedById(p, v) == 0) {
        if (BTL_POKEPARAM_HasType(BTL_SERVER_FLOW_GetPokeParam(p, v), 3) != 0) {
            t = BTL_SERVER_FLOW_AllocCmdRecord(p, 0x1a, v);
            t[7] = x;
            t[4] = 3;
            for (i = 1; i < 3; i++)
                t[i + 4] = 0;
            if (t[4] > 1)
                t[5] |= 0x80;
            BTL_SERVER_FLOW_CommitCmdRecord(p, t);
        } else {
            q = BTL_SERVER_FLOW_AllocCmdRecord(p, 0xc, 0x1f);
            q[1] = 5;
            if ((u32)cmpid(a, x).v > 1)
                q[2] = func_021E8A58();
            else
                q[2] = BTLV_CORE_MakeSlotKind1Empty();
            *((u8 *)q + 0xf) = v;
            BTL_SERVER_FLOW_CommitCmdRecord(p, q);
        }
    }
}
