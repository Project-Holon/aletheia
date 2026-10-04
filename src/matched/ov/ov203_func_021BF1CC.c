/*
 * function: func_021BF1CC
 * address: 0x021BF1CC
 * packet: pkt_ov203_021BF1CC
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02023F60 0x02023F60 thumb
 *   func_02031194 0x02031194 arm
 *   func_021BEFC4 0x021BEFC4 thumb ov203
 */
typedef unsigned int   u32;
extern void func_02023F60(u32 a0, u32 a1, u32 mask);
extern void func_02031194(void *);
extern void func_021BEFC4(char *,int,int,int,int,int,int *);
void func_021BF1CC(void *task,char *work)
{
    if(*(int *)(*(char **)work+0xC)) {
        func_02023F60(*(signed char *)(work+0xB),*(unsigned *)(work+0x1C),*(unsigned *)(work+0x18));
        func_02031194(task);return;
    }
    switch(*(signed char *)(work+8)) {
    case 0:
        if(*(int *)(work+0x14)==0) {
            func_021BEFC4(*(char **)work,*(int *)(work+0x18),*(int *)(work+0x1C),*(signed char *)(work+0xA),*(signed char *)(work+0xB),*(int *)(work+0x10),(int *)(work+0x14));
            (*(signed char *)(work+8))++;
        }
        break;
    case 1:
        if(*(int *)(work+0x14)) return;
        break;
    }
    func_02023F60(*(signed char *)(work+0xB),*(unsigned *)(work+0x1C),*(unsigned *)(work+0x18));
    func_02031194(task);
}
