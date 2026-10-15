/*
 * function: B_PLIST_DRAW_ApplyActorPalettes
 * address: 0x0220E7E4
 * packet: pkt_ov198_0220E7E4
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKE_TOOL_CalcIconPalette 0x0201BB5C thumb
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct {u8 half:3; u8 middle:4; u8 egg:1;} Flags;
typedef struct {char pad0[8];u16 species;char padA[34];unsigned form;char rest[28];} Record;
extern unsigned POKE_TOOL_CalcIconPalette(unsigned,unsigned,unsigned,unsigned);
typedef unsigned int   u32;
struct Obj;
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
void B_PLIST_DRAW_ApplyActorPalettes(Record *records)
{
    char *p=(char *)records;
    char *flags;
    short i;
    unsigned value;
    i=0;
    flags=p+0x1b;
    for(;i<6;i++) {
        if(records[i].species!=0) {
            value=POKE_TOOL_CalcIconPalette(records[i].species,records[i].form,((Flags *)(flags+i*0x4c))->half,((Flags *)(flags+i*0x4c))->egg);
            CLACT_SetActorPaletteOffset(*(void **)(p+i*4+0x1ed8),value,1);
        }
    }
}
