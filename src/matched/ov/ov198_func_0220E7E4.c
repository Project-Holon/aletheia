/*
 * function: func_0220E7E4
 * address: 0x0220E7E4
 * packet: pkt_ov198_0220E7E4
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201BB5C 0x0201BB5C thumb
 *   func_0204B6F4 0x0204B6F4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct {u8 half:3; u8 middle:4; u8 egg:1;} Flags;
typedef struct {char pad0[8];u16 species;char padA[34];unsigned form;char rest[28];} Record;
extern unsigned func_0201BB5C(unsigned,unsigned,unsigned,unsigned);
extern void func_0204B6F4(void *,unsigned,unsigned);
void func_0220E7E4(Record *records)
{
    char *p=(char *)records;
    char *flags;
    short i;
    unsigned value;
    i=0;
    flags=p+0x1b;
    for(;i<6;i++) {
        if(records[i].species!=0) {
            value=func_0201BB5C(records[i].species,records[i].form,((Flags *)(flags+i*0x4c))->half,((Flags *)(flags+i*0x4c))->egg);
            func_0204B6F4(*(void **)(p+i*4+0x1ed8),value,1);
        }
    }
}
