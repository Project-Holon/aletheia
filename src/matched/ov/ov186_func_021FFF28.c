/*
 * packet: pkt_ov186_021FFF28
 * function: BR_POKESEARCH_CreateGroupWindows
 * address: 0x021FFF28
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * region: ov186
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_RES_LoadBgGraphics 0x021FB964 thumb ov186
 *   BR_RES_GetFont 0x021FC20C thumb ov186
 *   BR_RES_GetMsgData 0x021FC214 thumb ov186
 *   BR_UTIL_Create 0x021FC6A4 thumb ov186
 *   BR_UTIL_SetTextLayout 0x021FC868 thumb ov186
 *   BR_UTIL_SetTextFromMessage 0x021FC754 thumb ov186
 */
extern void BR_RES_LoadBgGraphics(void *ctx, unsigned kind, unsigned short heap);
extern unsigned BR_RES_GetFont(char *p);
extern int BR_RES_GetMsgData(char *);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void *BR_UTIL_Create(unsigned short plane, unsigned a, unsigned short b, unsigned short c, unsigned char d, unsigned char e, void *owner, unsigned short heap);
extern void BR_UTIL_SetTextLayout(u8 *p, u32 a, u32 b, u32 c);
extern void BR_UTIL_SetTextFromMessage(char *, void *, void *, void *, unsigned short);
typedef struct Work { char pad0[0x14]; unsigned char flags[9]; char pad1[7]; unsigned short heap; unsigned short pad2; char *owner; char pad3[0x10]; void *resource; char *slots[9]; char pad4[0xc]; int state; } Work;
void BR_POKESEARCH_CreateGroupWindows(Work *p)
{
    int a, b, i;
    unsigned color;
    unsigned char x, y;
    p->state = 0;
    BR_RES_LoadBgGraphics((void *)((int)p->owner), 20, p->heap);
    a = BR_RES_GetFont(p->owner);
    b = BR_RES_GetMsgData(p->owner);
    for (i = 0; i < 9; i++) {
        x = (i % 5) * 6 + 2;
        y = 6;
        if (i < 5) y = 0;
        p->slots[i] = BR_UTIL_Create(4, (unsigned char)x, (unsigned char)(y + 4), (unsigned)4, 2, 14, p->resource, p->heap);
        color = 0x3da0;
        if (!p->flags[i]) color = 0x2da0;
        BR_UTIL_SetTextLayout((u8 *)p->slots[i], (int)0, (int)0, (int)1);
        BR_UTIL_SetTextFromMessage(p->slots[i], (void *)b, (void *)(i + 0x3a), (void *)a, color);
    }
}
