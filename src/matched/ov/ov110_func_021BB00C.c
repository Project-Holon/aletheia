/*
 * function: func_021BB00C
 * address: 0x021BB00C
 * packet: pkt_ov110_021BB00C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: struct member keeps the far offset in-loop; array store uses i++.
 * symbols:
 *   STRBUF_GetEosChar 0x02045A98 arm
 *   STRBUF_SetString 0x02045924 arm
 *   func_021BB214 0x021BB214 thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern u16 STRBUF_GetEosChar(void);
typedef unsigned int   u32;
struct Strbuf;
extern void STRBUF_SetString(struct Strbuf *o, const u16 *src);
extern u16 func_021BB214(u32 i);
typedef struct { u8 pad[0xad4]; u16 values[13]; } Input;
void func_021BB00C(Input *p,void *q) {
    u16 a[14];
    int i;
    for(i=0;i<13;) {
        u16 x;
        x=p->values[i];
        if(x==255) { a[i]=STRBUF_GetEosChar(); break; }
        a[i++]=func_021BB214(x);
    }
    a[13]=STRBUF_GetEosChar();
    STRBUF_SetString(q,a);
}
