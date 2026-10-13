/*
 * function: DWC_RAPCOMMON_CreateHeap
 * address:  0x02157048
 * packet:   pkt_ov009_02157048
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _pRapHeap  0x021A8268  data  ov009  a4
 *   d_021A1C78  0x021A1C78  data  ov009  a1
 *   d_021A1C7C  0x021A1C7C  data  ov009  a1
 *   func_02034714  0x02034714  arm
 *   func_02030734  0x02030734  arm
 *   func_02060C5C  0x02060C5C  arm
 */

typedef unsigned int u32;
typedef unsigned short u16;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fC;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1C;
    u16 f20;
} Obj;

extern Obj *_pRapHeap;
extern char d_021A1C78[];
extern char d_021A1C7C[];

extern void func_02034714(const char *expr, u32 line, const char *file);
extern void *func_02030734(u32 heap, u32 size, int align, const char *file, u16 line);
extern void *func_02060C5C(void *start, u32 size, u32 attr);

void DWC_RAPCOMMON_CreateHeap(u32 a, u32 b)
{
    if (_pRapHeap != 0) {
        func_02034714(d_021A1C78, 0, d_021A1C78);
    }
    _pRapHeap = (Obj *)func_02030734(0, 0x24, 1, d_021A1C7C, 0x14C);
    _pRapHeap->f4 = (u32)func_02030734(a, b - 0x80, 0, d_021A1C7C, 0x14D);
    _pRapHeap->f0 = (u32)func_02060C5C((void *)((_pRapHeap->f4 + 0x1f) & ~0x1f), b - 0xc0, 0);
    _pRapHeap->f20 = 0;
}
