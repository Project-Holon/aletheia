/*
 * function: func_021BDB08
 * address: 0x021BDB08
 * packet: pkt_ov208_021BDB08
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 021BDB52..021BDB54 is two-byte zero alignment padding.
 * matching: initialize the byte counter before reading the count, keeping its address in r3.
 * symbols:
 *   func_021BD2E0 0x021BD2E0 thumb ov208
 */
extern int func_021BD2E0(char *);
struct State { char pad[0x68]; unsigned char count; };
unsigned func_021BDB08(const struct State *p)
{
    int key=func_021BD2E0(*(char **)((char *)p+0x30));
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
                if(key==*(int *)entry) { result=*(unsigned *)(entry+0xc); break; }
            }
            break;
        }
    }
    return result;
}
