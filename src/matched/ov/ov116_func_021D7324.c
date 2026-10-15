/*
 * function: WIFI_BSUBWAY_GRAPHIC_ParseCodeIn
 * address: 0x021D7324
 * packet: pkt_ov116_021D7324
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STRBUF_GetEosChar 0x02045A98 arm
 *   STRBUF_GetChars 0x02045A90 arm
 */
#include "../include/Obj22625.h"
#include "../include/Obj22626.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 STRBUF_GetEosChar(void);
struct U16Vec;
extern u16 *STRBUF_GetChars(struct U16Vec *vec);
u32 WIFI_BSUBWAY_GRAPHIC_ParseCodeIn(u8 *p) {
    u16 end=STRBUF_GetEosChar();
    u16 *s=STRBUF_GetChars(((struct Obj22626 *)(*(u8 * *)&((struct Obj22625 *)p)->f1840))->f20);
    u32 value=0;
    u16 i=0;
    while(s[i]!=end) {
        u16 d=(u16)(s[i]-48);
        if(d>=10) d=(u16)(s[i]-0xff10);
        value *= 10;
        value += d;
        i++;
    }
    return value;
}
