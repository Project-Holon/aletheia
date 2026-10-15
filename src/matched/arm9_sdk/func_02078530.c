/*
 * function: FS_GetArchiveName
 * address:  0x02078530
 * packet:   pkt_02078530
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
*/

typedef struct FSArchive {
    union {
        char ptr[4];
        unsigned int pack;
        char *name;
    } name;
} FSArchive;

char *FS_GetArchiveName(FSArchive *arc)
{
    if (arc->name.ptr[3] != 0) {
        return arc->name.name;
    }
    return arc->name.ptr;
}
