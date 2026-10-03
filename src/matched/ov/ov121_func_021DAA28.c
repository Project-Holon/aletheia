/*
 * function: func_021DAA28
 * address: 0x021DAA28
 * packet: pkt_ov121_021DAA28
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding after the return.
 * lever: case 0 is an eight-byte aggregate copy (existing pair-copy idiom).
 * symbols:
 *   func_020437DC 0x020437DC arm
 *   func_020437E4 0x020437E4 arm
 */
typedef unsigned int u32;
typedef struct { int x,y; } Pair;
extern u32 func_020437DC(int);
extern u32 func_020437E4(int);
struct StrObj;
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0201D42C(void *,int);
void func_021DAA28(char *p,int a,int *out)
{
    int x,y;
    switch(*(int *)(p+20)) {
    case 0:
        *(Pair *)out=*(Pair *)(p+12);
        break;
    case 1:
        x=func_020437DC(*(int *)p)/2;
        y=func_020437E4(*(int *)p)/2;
        x-=func_0201D304(*(void **)(p+24),a,0)/2;
        y-=func_0201D42C(*(void **)(p+24),a)/2;
        out[0]=x+*(int *)(p+12);
        out[1]=y+*(int *)(p+16);
        break;
    case 2:
        x=func_020437E4(*(int *)p)/2;
        x-=func_0201D42C(*(void **)(p+24),a)/2;
        out[0]=*(int *)(p+12);
        out[1]=x+*(int *)(p+16);
        break;
    }
}
