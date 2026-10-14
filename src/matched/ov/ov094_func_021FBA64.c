/*
 * function: BTLV_EFFVM_CmdPlaySe
 * address:  0x021FBA64
 * packet:   pkt_ov094_021FBA64
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   BTLV_EFFVM_StartSePlayTask  0x021F9858  thumb  ov094
 */
typedef struct {
    char pad[0x23c];
    int f23c;
} State;

struct Cursor;
extern unsigned int VM_GetU32(struct Cursor *p);
typedef unsigned int   u32;
extern void BTLV_EFFVM_StartSePlayTask(void *vm, u32 a, int b, u32 c, int e, u32 f, int g, int h, int d);

int BTLV_EFFVM_CmdPlaySe(struct Cursor *a, State *s)
{
    int v0 = VM_GetU32(a);
    int v1 = VM_GetU32(a);
    int v2 = VM_GetU32(a);
    int v3 = VM_GetU32(a);
    int v4 = VM_GetU32(a);
    int v5 = VM_GetU32(a);
    int v6 = VM_GetU32(a);
    int v7 = VM_GetU32(a);

    VM_GetU32(a);
    BTLV_EFFVM_StartSePlayTask((void *)a, v0, v1, v2, v4, v5, v6, v7, v3);
    return s->f23c;
}
