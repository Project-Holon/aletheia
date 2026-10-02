/*
 * function: func_0216F7F4
 * address: 0x0216F7F4
 * packet: pkt_ov010_0216F7F4
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_02172B64 0x02172B64 data ov010 a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 *f00; void *f04; void *f08; u32 f0c; u32 f10; u32 f14; } Record;
extern char d_02172B64[];
extern void *func_02030734(u32,u32,int,const char *,u16);
Record *func_0216F7F4(void *a,u8 *b,u32 heap) { Record *p; p=func_02030734(heap,24,1,d_02172B64,0x33a); p->f00=b; p->f04=a; p->f0c=0; b[4]=b[4]&~0x40; p->f00[4]|=0x80; return p; }
