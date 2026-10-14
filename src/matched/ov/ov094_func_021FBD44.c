/*
 * function: BTLV_EFFVM_CmdJumpIf
 * address:  0x021FBD44
 * packet:   pkt_ov094_021FBD44
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   BTLV_EFFVM_EvalCondition  0x021FDBB0  thumb  ov094
 *   BTLV_EFFVM_CompareAndJump  0x021FBDD4  thumb  ov094
 */
typedef struct {
    char pad[0x23c];
    int f23c;
} State;

typedef unsigned int   u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern int BTLV_EFFVM_EvalCondition(State *s, int i);
extern void BTLV_EFFVM_CompareAndJump(int a, int b, int c, int d, int e);

int BTLV_EFFVM_CmdJumpIf(struct Cursor *a, State *s)
{
    int x = BTLV_EFFVM_EvalCondition(s, VM_GetU32(a));
    int op = VM_GetU32(a);
    int y = VM_GetU32(a);
    int z = VM_GetU32(a);

    BTLV_EFFVM_CompareAndJump((int)a, x, y, op, z);
    return s->f23c;
}
