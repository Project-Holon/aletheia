/*
 * function: func_021C4918, func_021C4948
 * address: 0x021C4918
 * packet: pkt_ov127_021C4918
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * unit: yes
 * symbols:
 *   func_021C4A98 0x021C4A98 thumb ov127
 *   func_02082BCC 0x02082BCC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern u8 *func_021C4A98(void *);
extern void func_02082BCC(void *,int,int);
void func_021C4918(void *a,u16 *s) { u8 *p; s16 x,y;p=func_021C4A98(a);x=(s16)s[0];y=(s16)s[1];*(s16 *)(p+4)=x;*(s16 *)(p+6)=y;*(s16 *)(p+8)=x;*(s16 *)(p+10)=y;*(u16 *)(p+12)=s[2];p[21]=s[3];p[20]=s[4];*(u16 *)(p+14)=s[5];*(u32 *)p=1; }
void func_021C4948(void *p) { func_02082BCC(p,0,24); }
