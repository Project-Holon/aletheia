/*
 * function: func_021DA1A8
 * address: 0x021DA1A8
 * packet: pkt_ov129_021DA1A8
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Lever: declare i before y, initialise j after loading y, and keep the equality arm separate.
 * symbols:
 *   func_0204B454 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 */
typedef short s16;
typedef unsigned char u8;
typedef struct { s16 x,y,z,w; } Position;
struct Actor;
struct PtS;
extern void func_0204B454(struct Actor *actor, struct PtS *out, unsigned int space);
extern void func_0204B404(int,void *,int);
void func_021DA1A8(char *p,int animate)
{
    Position s;
    int i,j;
    s16 y=*(s16 *)((unsigned)p+(unsigned)*(int *)(p+0x240)*2+0x214);
    unsigned q;
    j=0;
    for(i=0;i<*(int *)(p+0x23c);i++) {
        if(i>=*(int *)(p+0x248) && i<*(int *)(p+0x24c)) {
            if(i==*(int *)(p+0x248)) y+=20;
            else y+=32;
        } else {
            if(i==0) y+=20;
            else y+=8;
        }
        q=(unsigned)p+(unsigned)i*28;
        func_0204B454((struct Actor *)*(int *)(q+12),(struct PtS *)&s.z,0);
        if(animate==0) {
            s.z=y;
            func_0204B404(*(int *)(q+12),&s.z,0);
        } else {
            *(s16 *)(q+0x14)=(y-s.z)/4;
            *(s16 *)(q+0x16)=0;
            *(u8 *)(q+0x18)=4;
            *(u8 *)(q+0x19)=0;
        }
        q=(unsigned)p+(unsigned)j*28;
        if(i==*(int *)(q+0x150) && j!=2) {
            func_0204B454((struct Actor *)*(int *)(q+0x15c),(struct PtS *)&s,0);
            if(*(int *)(p+0x248)==*(int *)(p+0x24c)) y+=8;
            else {
                if(i>*(int *)(p+0x248) && i<*(int *)(p+0x24c)) y+=20;
                else y+=8;
            }
            if(animate==0) {
                s.x=y;
                func_0204B404(*(int *)(q+0x15c),&s,0);
            } else {
                *(s16 *)(q+0x164)=(y-s.x)/4;
                *(s16 *)(q+0x166)=0;
                *(u8 *)(q+0x168)=4;
            }
            j++;
        }
    }
}
