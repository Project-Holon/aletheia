/*
 * function: func_0215CAB4
 * address:  0x0215CAB4
 * packet:   pkt_ov010_0215CAB4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: reads one halfword and the system, boxes them in an
 * 8-byte record and opens overlay 0xAE over it.
 *
 * Bytes exact.
 *
 * 2026-10-05 (wave D9): EXACT. The ov174 token on the d_021B74A0 data line (the
 * proc table lives in ov174, which this function loads) gave the witness; the
 * ov174_id word then resolved through the overlay_id walk. Source unchanged.
 *
 * symbols:
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02030734  0x02030734  arm
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0215C63C  0x0215C63C  thumb  ov010
 *   d_021728F0     0x021728F0  data  a1
 *   ov174_id       0x000000AE  data
 *   d_021B74A0     0x021B74A0  data  a1 ov174
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Box8 {
    u16 v;              /* 0x00 */
    u16 pad02;
    void *sys;          /* 0x04 */
} Box8;

extern unsigned int func_02159B10(void *a0, void *a1);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_0215A5E4(void *vm);
extern void func_0215C63C(void *c, void *vm, u32 ovId, const void *proc, void *work, u32 arg0, u32 arg1);
extern const char d_021728F0[];
extern const u8 d_021B74A0[];
extern u8 ov174_id[];

int func_0215CAB4(void *c, void *vm)
{
    u16 v;
    Box8 *b;

    v = func_02159B10(c, vm);
    b = func_02030734(4, 8, 1, d_021728F0, 0x205);
    b->v = v;
    b->sys = func_0215A5E4(vm);
    func_0215C63C(c, vm, (u32)ov174_id, d_021B74A0, b, 0, 0);
    return 1;
}
