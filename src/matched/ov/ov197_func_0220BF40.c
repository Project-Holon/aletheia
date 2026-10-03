/*
 * function: func_0220BF40
 * address: 0x0220BF40
 * packet: pkt_ov197_0220BF40
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * matching: naming unsigned index before the u8 palette settles r0/r2;
 *   unnamed repeated index loads differ in18 bytes. Callee uses u8 palette.
 * symbols:
 *   func_0202CE50 0x0202CE50 thumb
 *   func_0202CC58 0x0202CC58 thumb
 *   d_0220DB44 0x0220DB44 data a1
 */
typedef unsigned char u8;
struct Row { u8 a,b,c,d; };
extern const struct Row d_0220DB44[];
extern void func_0202CE50(void *,unsigned,int,int,u8,u8,u8);
extern void func_0202CC58(void *,unsigned);
void func_0220BF40(char *p)
{
    if(*(u8 *)(p+0x527)) {
        switch(*(u8 *)(p+0x524)) {
        case 0: {
            unsigned index=*(u8 *)(p+0x526);
            u8 color;
            color=2;
            if(index<10) color=5;
            func_0202CE50(*(void **)(p+0x520),index,0,0,d_0220DB44[index].c,d_0220DB44[index].d,color);
            func_0202CC58(*(void **)(p+0x520),*(u8 *)(p+0x526));
            (*(u8 *)(p+0x524))++;
            break;
        }
        case 1: {
            unsigned index;
            u8 color;
            if(*(u8 *)(p+0x525)==4) {
                index=*(u8 *)(p+0x526);
                color=1;
                if(index<10) color=4;
                func_0202CE50(*(void **)(p+0x520),index,0,0,d_0220DB44[index].c,d_0220DB44[index].d,color);
                func_0202CC58(*(void **)(p+0x520),*(u8 *)(p+0x526));
                *(u8 *)(p+0x525)=0;
                (*(u8 *)(p+0x524))++;
            } else (*(u8 *)(p+0x525))++;
            break;
        }
        case 2:
            if(*(u8 *)(p+0x525)==1) {
                *(u8 *)(p+0x525)=0;
                *(u8 *)(p+0x524)=0;
                *(u8 *)(p+0x527)=0;
            } else (*(u8 *)(p+0x525))++;
            break;
        }
    }
}
