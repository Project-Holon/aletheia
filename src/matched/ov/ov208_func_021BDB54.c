/*
 * function: func_021BDB54
 * address: 0x021BDB54
 * packet: pkt_ov208_021BDB54
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 021BDB9E..021BDBA0 is two-byte zero alignment padding.
 * matching: initialize the byte counter before reading the bound.
 * symbols:
 *   func_021BD308 0x021BD308 thumb ov208
 */
extern int func_021BD308(void *);
struct State { char pad[0x68]; unsigned char count; };
unsigned func_021BDB54(const struct State *p)
{
    int key=func_021BD308(*(char **)((char *)p+0x30));
    unsigned result=0;
    unsigned char i;
    unsigned count;
    char *entry;
    if(key!=-1) {
        switch(*(unsigned *)((char *)p+0x10)) {
        case 0: case 1: case 2:
            i=0;
            count=p->count;
            for(;i<count;i++) {
                entry=*(char **)((char *)p+i*8+0x6c);
                if(key==*(int *)entry) { result=*(unsigned *)(entry+0x10); break; }
            }
            break;
        }
    }
    return result;
}
