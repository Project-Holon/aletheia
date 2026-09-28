/*
 * function: SBServerFree
 * address:  0x0219DFF8
 * packet:   pkt_ov009_0219DFF8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SBServerFree (sb_server.o)
 *
 * symbols:
 *   TableFree    0x021846B4  arm
 *   gsifree      0x0217EAE0  arm
 */

struct HashImplementation;
struct _SBServer {
    char pad[0x18];
    struct HashImplementation *keys;
};

extern void TableFree(struct HashImplementation *table);
extern void gsifree(void *ptr);

void SBServerFree(void *elem)
{
    struct _SBServer *server = *(struct _SBServer **)elem;

    TableFree(server->keys);
    server->keys = 0;
    gsifree(server);
}
