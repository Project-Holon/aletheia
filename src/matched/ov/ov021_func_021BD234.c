/*
 * function: PLACE_NAME_LETTER_InitWork
 * address:  0x021BD234
 * packet:   pkt_ov021_021BD234
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   STRBUF_GetEosChar  0x02045A98  arm  arm9
 *   MI_CpuFill8  0x02082BCC  arm  arm9
 */

typedef unsigned short u16;

typedef struct {
    char pad[0x44];
    int f44;
    u16 h48;
} Obj;

extern void MI_CpuFill8(void *p, int v, int n);
extern u16 STRBUF_GetEosChar(void);

void PLACE_NAME_LETTER_InitWork(Obj *p)
{
    MI_CpuFill8(p, 0, 0x4C);
    p->f44 = 0;
    p->h48 = STRBUF_GetEosChar();
}
