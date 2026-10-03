/*
 * function: func_021BA8DC
 * address: 0x021BA8DC
 * packet: pkt_ov214_021BA8DC
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BB2A8 0x021BB2A8 thumb ov214
 *   func_021BAB0C 0x021BAB0C thumb ov214
 * layout: two rows of six 0x28-byte cells, observed nested-loop bounds.
 * prototypes: BAB0C owning matched source; B2A8 own same-region getter.
 * extent: 466-byte function followed by two zero alignment bytes at 021BAAAE.
 * lever: order-byte store inside each branch preserves original address CSE
 * and shared-tail layout; factoring it outside produced 430 bytes / DIFF316.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cell { u32 a,b,c,d,out0,out1,out2,out3,actor; u8 x,y,flag,order; };
struct S { u16 heap,pad2; u8 *owner; u8 pad8[0xBC]; struct Cell cells[2][6]; u32 spare,mode; };
extern u32 func_021BB2A8(u8 *);
extern int func_021BAB0C(int,u16,int,u8,u32,u32,u32,u32,void *,u8,u8,u8,u8,u8);
void func_021BA8DC(void *unused,struct S *p)
{
    int handle=func_021BB2A8(p->owner);
    u8 i,j;
    for(i=0;i<2;i++) for(j=0;j<6;j++) {
        p->cells[i][j].d=0;
        p->cells[i][j].flag=1;
    }
    for(i=0;i<2;i++) for(j=0;j<6;j++) {
        if(p->mode) {
            if(i==0) { *(u8 *)((u32)p+240*i+40*j+0xE8)=100+24*j; *(u8 *)((u32)p+240*i+40*j+0xE9)=64; *(u8 *)((u32)p+240*i+40*j+0xEB)=6-j; }
            else { *(u8 *)((u32)p+240*i+40*j+0xE8)=36+24*j; *(u8 *)((u32)p+240*i+40*j+0xE9)=112; *(u8 *)((u32)p+240*i+40*j+0xEB)=6-j; }
        } else {
            if(i==0) {
                if(j<3) { *(u8 *)((u32)p+240*i+40*j+0xE8)=172+24*j; *(u8 *)((u32)p+240*i+40*j+0xE9)=64; *(u8 *)((u32)p+240*i+40*j+0xEB)=6-j; }
                else { *(u8 *)((u32)p+240*i+40*j+0xE8)=172+24*(j-3); *(u8 *)((u32)p+240*i+40*j+0xE9)=88; *(u8 *)((u32)p+240*i+40*j+0xEB)=6-j; }
            } else {
                if(j<3) { *(u8 *)((u32)p+240*i+40*j+0xE8)=36+24*j; *(u8 *)((u32)p+240*i+40*j+0xE9)=88; *(u8 *)((u32)p+240*i+40*j+0xEB)=6-j; }
                else { *(u8 *)((u32)p+240*i+40*j+0xE8)=36+24*(j-3); *(u8 *)((u32)p+240*i+40*j+0xE9)=112; *(u8 *)((u32)p+240*i+40*j+0xEB)=6-j; }
            }
        }
    }
    for(i=0;i<2;i++) for(j=0;j<6;j++) {
        if(p->cells[i][j].a) {
            p->cells[i][j].actor=func_021BAB0C(handle,p->heap,0,0,
                p->cells[i][j].a,p->cells[i][j].b,p->cells[i][j].c,p->cells[i][j].d,
                &p->cells[i][j].out0,p->cells[i][j].x,p->cells[i][j].y,
                p->cells[i][j].flag,1,p->cells[i][j].order);
        }
    }
}
