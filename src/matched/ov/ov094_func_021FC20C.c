/*
 * function: BTLV_EFFVM_CmdCallScript
 * address: 0x021FC20C
 * packet: pkt_ov094_021FC20C
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   VM_Call 0x020113B4 thumb
 *   ARC_TOOL_LoadMember 0x02048F60 arm
 */
typedef unsigned short u16;
typedef struct {
    int pad0;
    int f4;
    char pad1[0xdc - 8];
    int fdc;
    int fe0;
    int a0[16];
    int a1[16];
    int a2[16];
    int a3[16];
    int f1e4;
    int *f1e8;
    char pad2[0x238 - 0x1ec];
    u16 h238;
    char pad3[2];
    int f23c;
    char pad4[0x260 - 0x240];
    int f260;
} State;
struct Cursor;
extern unsigned int VM_GetU32(struct Cursor *p);
struct Ring;
extern void VM_Call(struct Ring *r, unsigned int v);
typedef unsigned int   u32;
extern void *ARC_TOOL_LoadMember(u32 archive_id, u32 member, u32 heap);

int BTLV_EFFVM_CmdCallScript(struct Ring *a, State *s)
{
    int n = VM_GetU32((struct Cursor *)a);
    int v = VM_GetU32((struct Cursor *)a);
    int w = VM_GetU32((struct Cursor *)a);
    int *p;

    s->a0[s->f260] = s->fdc;
    s->a1[s->f260] = s->fe0;
    s->a2[s->f260] = (int)s->f1e8;
    s->a3[s->f260] = s->f4;
    if (v != 14) s->fdc = v;
    if (w != 16) s->fe0 = w;
    s->f4 = 0;
    p = ARC_TOOL_LoadMember(0x43, n - 0x231, (u16)((s->h238 & 0x7fff) | 0x8000));
    s->f1e8 = p;
    VM_Call(a, (unsigned int)((char *)p + p[1]));
    s->f260++;
    return s->f23c;
}
