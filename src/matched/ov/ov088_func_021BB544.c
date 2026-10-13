/*
 * function: STARTMENU_LoadRowBuffers
 * address:  0x021BB544
 * packet:   pkt_ov088_021BB544
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_02030734  0x02030734  arm
 *   ARC_UTIL_LoadPaletteDataFromHandle  0x02049EF4  arm
 *   MIi_CpuCopy16  0x02082A60  arm
 *   func_020307B0  0x020307B0  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   gStartMenuRowInfo     0x021BD5EC  data  ov088  a2
 *   d_021BDA00     0x021BDA00  data  ov088  a1
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct { u16 a; u16 b; } Ent;
extern const Ent gStartMenuRowInfo[8];
extern char d_021BDA00[];

extern void *func_020490F4(u32 id, u32 heap);
extern void *func_02030734(u32 heap, u32 size, int clear, const char *file, u16 line);
extern void *ARC_UTIL_LoadPaletteDataFromHandle(void *o, u32 a, u32 b, void **out, u16 e);
extern void MIi_CpuCopy16(void *srcp, void *destp, unsigned long size);
extern u32 func_020307B0(void *p);
extern void ARC_TOOL_DeleteHandle(void *h);

void STARTMENU_LoadRowBuffers(char *p)
{
    void *h = func_020490F4(0x23, 0x800B);
    u32 i;
    for (i = 0; i < 8; i++) {
        u32 sz = gStartMenuRowInfo[i].b * 0x34;
        void *out;
        void *r;
        *(u32 *)(p + i * 4 + 0xf8) = (u32)func_02030734(0xb, sz, 0, d_021BDA00, 0x7e9);
        r = ARC_UTIL_LoadPaletteDataFromHandle(h, gStartMenuRowInfo[i].a, 1, &out, 0xb);
        MIi_CpuCopy16((char *)out + 0xc, *(void **)(p + i * 4 + 0xf8), sz);
        func_020307B0(r);
    }
    ARC_TOOL_DeleteHandle(h);
}
