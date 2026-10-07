/*
 * file:     game_beacon_search_p20.c
 * unit:     yes
 * function: func_02165D10, func_02165D20, func_02165D28, func_02165D34
 * address:  0x02165D10
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef unsigned short u16;

typedef unsigned int u32;

struct S {u32 a,b,c;u32 low:16;u32 first:10;u32 second:6;};

typedef unsigned char u8;

typedef struct Rec {
    u8 pad00[3];
    u8 lo : 7;
    u8 hi : 1;
} Rec;

struct Bits_02165D28 { unsigned a; unsigned low:17; unsigned value:10; unsigned high:5; };

struct Bits_02165D34 { unsigned a, b; unsigned low:22; unsigned value:10; };

void func_02165D10(const struct S *p,u16 *a,u16 *b);
u8 func_02165D20(Rec *r);
unsigned short func_02165D28(const struct Bits_02165D28 *p);
unsigned short func_02165D34(const struct Bits_02165D34 *p);

/*
 * blocker-leaf: ov216 021BD174 MATCH*; parent ownership cleared; no source/unit/shard; full original getter body read.
 * tail: 2B zero padding 02165D1E.
 */
void func_02165D10(const struct S *p,u16 *a,u16 *b)
{
    *a=p->first;
    *b=p->second;
}


/*
 * Low seven bits of byte 3 (unlabelled leaf; sibling of func_02165D08).
 */
u8 func_02165D20(Rec *r)
{
    return r->lo;
}

/*
 * Parent-cleared leaf for ov216 021BCE04. ov010 coherent Thumb accessor;
 * overlapping ov009 address is interior ARM code, as explicit shows prove.
 */
unsigned short func_02165D28(const struct Bits_02165D28 *p) { return p->value; }

/*
 * Parent-cleared leaf for ov216021BD448 after same-region source/unit/shard
 * and SDK union checks. Coherent ov010 Thumb accessor; ov009 is interior ARM.
 */
unsigned short func_02165D34(const struct Bits_02165D34 *p) { return p->value; }
