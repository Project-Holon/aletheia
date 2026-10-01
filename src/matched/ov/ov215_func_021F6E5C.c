/*
 * function: func_021F6E5C
 * address: 0x021F6E5C
 * packet: pkt_ov215_021F6E5C
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 515B4 receives visibly loaded r1/r2 despite legacy one-argument callee.
 * symbols:
 *   func_020515B4 0x020515B4 arm
 *   func_02051620 0x02051620 arm
 *   d_021F73B4 0x021F73B4 data a4
 */
typedef unsigned short u16;
typedef struct { int x,y,z; } Vec;
extern const Vec d_021F73B4;
extern void func_020515B4(void *,int,Vec *);
extern void func_02051620(void *);
void func_021F6E5C(char *p)
{
    if (*(int *)(p+0x4814)) {
        Vec v=d_021F73B4;
        while (*(u16 *)(p+2)<*(u16 *)(p+4)) {
            const char *table=*(const char **)(p+8);
            unsigned index=*(u16 *)(p+2);
            u16 frame=*(u16 *)p;
            u16 key=*(u16 *)(table+(int)index*4);
            if (frame!=key) break;
            func_020515B4(*(void **)(p+*(unsigned char *)(table+index*4+2)*0x4808+0x480c),*(unsigned char *)(table+index*4+3),&v);
            (*(u16 *)(p+2))++;
        }
        (*(u16 *)p)++;
    }
    if (*(int *)(p+0x4818)>=0) {
        if (*(int *)(p+0x4818)==0) func_02051620(*(void **)(p+0x480c));
        (*(int *)(p+0x4818))--;
    }
}
