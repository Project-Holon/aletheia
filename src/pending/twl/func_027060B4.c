/*
 * function: func_027060B4
 * address:  0x027060B4
 * region:   twl
 * isa:      arm
 * lang:     c99
 * flags:    -O4,p
 *
 * symbols:
 *   data_027344D8  0x027344D8  data twl a2
 *   data_02732D78  0x02732D78  data twl a2
 *   func_02705ED0  0x02705ED0  arm twl a2
 *   func_02705F28  0x02705F28  arm twl a2
 *   func_02705FAC  0x02705FAC  arm twl a2
 *   func_02706D28  0x02706D28  arm twl a2
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
/* 0x50 bytes: the next symbol, the OSAlarm at 0x027344FC (0x2C bytes), is its
   field at 0x24 and the object ends at data_02734528. The full size keeps the
   f18 store an exact alias object, so it gets no edge to the message stores. */
typedef struct DspSys {
    u32 f0; u32 f4; u32 f8; u32 fc; u32 f10; u32 f14; u32 f18; u32 f1c; u32 f20;
    u32 alarm[11];
} DspSys;
extern DspSys data_027344D8;
extern int data_02732D78;
extern void *func_02705ED0(int);
extern void func_02705F28(void *, int, void *, u16);
extern void func_02705FAC(u32, u32, u32);
extern void func_02706D28(int, void (*)(u32, u32, u32), int);

#define SWAP16(x) (((x) >> 16) | ((x) << 16))

void func_027060B4(u32 a0, u32 a1, u32 a2, int a3)
{
    u32 msg[4];
    int zero = 0;
    void *h = func_02705ED0(zero);
    if (h == 0) {
        return;
    }
    if (data_02732D78 < a3) {
        return;
    }
    data_02732D78 = a3;
    func_02706D28(2, func_02705FAC, zero);
    data_027344D8.f18 = 1;
    msg[0] = SWAP16(a2 | 0x1100);
    msg[1] = SWAP16(a0);
    msg[2] = SWAP16(a1 / 2);
    msg[3] = zero;
    func_02705F28(h, 2, msg, 0x10);
}
