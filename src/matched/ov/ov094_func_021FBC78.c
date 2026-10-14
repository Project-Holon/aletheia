/*
 * function: BTLV_EFFVM_CmdStartSeVolumeTask
 * address:  0x021FBC78
 * packet:   pkt_ov094_021FBC78
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   BTLV_EFFVM_StartSeVolumeTask  0x021F9948  thumb  ov094
 */
typedef struct {
    char pad[0x23c];
    int f23c;
} State;

struct Cursor;
extern unsigned int VM_GetU32(struct Cursor *p);
typedef unsigned int   u32;
extern void BTLV_EFFVM_StartSeVolumeTask(void *vm, u32 a, int mode, int c, int x, int dest, int e, int f, int g, int duration);

int BTLV_EFFVM_CmdStartSeVolumeTask(struct Cursor *a, State *s)
{
    int v0 = VM_GetU32(a);
    int v1 = VM_GetU32(a);
    int v2 = VM_GetU32(a);
    int v3 = VM_GetU32(a);
    int v4 = VM_GetU32(a);
    int v5 = VM_GetU32(a);
    int v6 = VM_GetU32(a);
    int v7 = VM_GetU32(a);
    int v8 = VM_GetU32(a);

    BTLV_EFFVM_StartSeVolumeTask((void *)a, v0, v1, v2, v3, v4, v5, v6, v7, v8);
    return s->f23c;
}
