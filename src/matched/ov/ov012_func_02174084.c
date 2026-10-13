/*
 * function: UNION_COMMAND_SendAppLeaveData
 * address:  0x02174084
 * packet:   pkt_ov012_02174084
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_02087C6C  0x02087C6C  arm
 *   func_020399A8  0x020399A8  arm
 *   func_0203D4D0  0x0203D4D0  arm
 */

typedef struct { int w[8]; } B32;
typedef struct { B32 a; unsigned char t[8]; } Msg;

extern void func_02082BCC(void *p, int v, int n);
extern void func_02087C6C(void *p);
struct Entry;
extern struct Entry *func_020399A8(void);
typedef unsigned int   u32;
extern u32 func_0203D4D0(u32 entry, u32 mask, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);

void UNION_COMMAND_SendAppLeaveData(int a, B32 *src)
{
    Msg m;

    func_02082BCC(&m, 0, 0x28);
    m.a = *src;
    func_02087C6C(m.t);
    func_0203D4D0((int)func_020399A8(), a, 0x1413, 0x28, (u32)(&m), 1, 0, 0);
}
