/*
 * function: func_0215F4F4
 * address: 0x0215F4F4
 * packet: pkt_ov010_0215F4F4
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0215A5F4 0x0215A5F4 thumb ov010
 *   func_02158F54 0x02158F54 thumb ov010
 *   func_020120F4 0x020120F4 thumb
 *   func_0201296C 0x0201296C thumb
 *   func_0215911C 0x0215911C thumb ov010
 *   func_0215A500 0x0215A500 thumb ov010
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef struct Entry { u32 a; u16 b,c; } Entry;
extern void *func_0215A5F4(void *);
extern void *func_02158F54(void *);
extern void *func_020120F4(void *);
extern void *func_0201296C(void *);
extern Entry *func_0215911C(void *);
extern void func_0215A500(void *,u32);
int func_0215F4F4(void *a,void *b) { void *p; void *s; int i; Entry *t; p=func_0215A5F4(b); s=func_0201296C(func_020120F4(func_02158F54(p))); t=func_0215911C(p); for(i=0;i<0x6b;i++) func_0215A500(s,t[i].c); return 0; }
