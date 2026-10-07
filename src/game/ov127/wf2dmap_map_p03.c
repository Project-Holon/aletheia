/*
 * file:     wf2dmap_map_p03.c
 * unit:     yes
 * function: func_021C4A98, func_021C4AC4
 * address:  0x021C4A98
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef unsigned short u16;

struct pair { u16 a,b; };

char *func_021C4A98(unsigned *p);
struct pair func_021C4AC4(char *p);

char *func_021C4A98(unsigned *p)
{
 unsigned i=0;
 if (i<p[1]) { char *base=(char *)p[0];
 do { if (*(unsigned *)(base+i*24)==0) return base+i*24; i++; } while(i<p[1]); }
 return 0;
}

struct pair func_021C4AC4(char *p) { return *(struct pair *)(p+4); }
