/*
 * function: WIFI_BSUBWAY_StatusSetMessage
 * address: 0x021D6B88
 * packet: pkt_ov116_021D6B88
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 021D6C4E follow the epilogue.
 * evidence: 0217BC44's full ov009 ARM wrapper forwards r0-r3 and
 * three full-word stack arguments to 0217B828; this caller supplies all7.
 * symbols:
 *   func_02012944 0x02012944 thumb
 *   MYSTATUS_Copy 0x02008494 thumb
 *   func_02008510 0x02008510 thumb
 *   MI_CpuFill8 0x02082BCC arm
 *   STRBUF_GetChars 0x02045A90 arm
 *   STRBUF_GetLength 0x020458F8 arm
 *   STRBUF_GetEosChar 0x02045A98 arm
 *   DWC_CheckProfanityExAsync 0x0217BC44 arm ov009
 *   STRBUF_Delete 0x02045808 arm
 */
#include "../include/Obj04469.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 *func_02012944(void *);
extern void MYSTATUS_Copy(void *, void *);
extern void *func_02008510(void *, int);
extern void MI_CpuFill8(void *, u8, u32);
struct U16Vec;
extern u16 *STRBUF_GetChars(struct U16Vec *vec);
extern u16 STRBUF_GetLength(struct U16Vec *vec);
extern u16 STRBUF_GetEosChar(void);
extern int DWC_CheckProfanityExAsync(unsigned short **words, int wordsnum, char *reserved, int timeout, char *result, int *badwordsnum, int region);
extern void STRBUF_Delete(struct U16Vec *vec);
void WIFI_BSUBWAY_StatusSetMessage(u8 *p, void *save, int id)
{
    void *str;
    u16 *chars;
    u32 i;
    MYSTATUS_Copy(func_02012944(save), ((struct Obj04469 *)p)->f218);
    str = func_02008510(((struct Obj04469 *)p)->f218, id);
    MI_CpuFill8(p + 0x1f0, 0, 40);
    ((struct Obj04469 *)p)->f214 = id;
    chars = STRBUF_GetChars(str);
    for (i = 0; i < STRBUF_GetLength(str) + 1u; i++) {
        u16 c = chars[i];
        if (c == STRBUF_GetEosChar()) ((u16 *)(p + 0x1f0))[i] = 0;
        else ((u16 *)(p + 0x1f0))[i] = c;
    }
    ((struct Obj04469 *)p)->f208 = p + 0x1f0;
    ((struct Obj04469 *)p)->f210 = 0;
    DWC_CheckProfanityExAsync((short unsigned int **)(p + 0x208), 1, 0, 0, (char *)(p + 0x20c), (int *)(p + 0x210), 128);
    STRBUF_Delete(str);
}
