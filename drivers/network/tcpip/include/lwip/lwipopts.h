/*
   ------------------------------------
   ---------- Memory options ----------
   ------------------------------------
*/

/* This combo allows us to implement malloc, free, and realloc ourselves */
#define MEM_LIBC_MALLOC                 1
#define MEMP_MEM_MALLOC                 1

/* Define LWIP_COMPAT_MUTEX if the port has no mutexes and binary semaphores
 should be used instead */
#define LWIP_COMPAT_MUTEX               1
#define LWIP_COMPAT_MUTEX_ALLOWED       1

#define MEM_ALIGNMENT                   4

#define LWIP_ARP                        1

#define ETH_PAD_SIZE                    2

#define ARP_QUEUEING                    0

#define IP_FORWARD                      0

#define IP_REASS_MAX_PBUFS              0xFFFFFFFF

#define IP_DEFAULT_TTL                  128

#define IP_SOF_BROADCAST                1

#define IP_SOF_BROADCAST_RECV           1

#define LWIP_ICMP                       1

#define LWIP_RAW                        1

#define LWIP_UDP                        1

#define LWIP_SNMP                       1

#define LWIP_DHCP                       0

#define LWIP_IP_ACCEPT_UDP_PORT(port)   ((port) == PP_NTOHS(68))

#define LWIP_AUTOIP                     0

#define LWIP_IGMP                       0

#define LWIP_DNS                        0

#define LWIP_TCP                        1

#define LWIP_CALLBACK_API               1

#define LWIP_NETIF_API                  1

#define LWIP_NETIF_LOOPBACK             1

#define SO_REUSE                        1

#define SO_REUSE_RXTOALL                1

/* FIXME: These MSS and TCP Window definitions assume an MTU
 * of 1500. We need to add some code to lwIP which would allow us
 * to change these values based upon the interface we are
 * using. Currently ReactOS only supports Ethernet so we're
 * fine for now but it does need to be fixed later when we
 * add support for other transport mediums */
#define TCP_MSS                         1460

/*
 * Phase 1 (CORE-20055): a large receive window plus window scaling prevents
 * high-bandwidth downloads from stalling on 64 KB window limits. Keep the send
 * buffer at the legacy 64 KB limit and increase packet-related pool sizes so
 * the larger window does not exhaust pbufs/segments at high packet rates. Add a
 * finer TCP timer for more responsive ACK clocking.
 */
#define TCP_TMR_INTERVAL                100
#define TCP_WND                         (1024 * 1024 - 16)
#define TCP_SND_BUF                     0xFFFF
#define LWIP_WND_SCALE                  1
#define TCP_RCV_SCALE                   4
#define TCP_SNDLOWAT                    8192

/*
 * Match pbuf/memp sizing to the larger window and packet rate.
 */
#define MEMP_NUM_PBUF                   128
#define MEMP_NUM_TCP_PCB                64
#define MEMP_NUM_TCP_SEG                512
#define MEMP_NUM_TCPIP_MSG_INPKT        256
#define PBUF_POOL_SIZE                  256

#define TCP_MAXRTX                      8

#define TCP_SYNMAXRTX                   4

#define TCP_LISTEN_BACKLOG              1

#define LWIP_TCP_TIMESTAMPS             1

#define LWIP_SOCKET                     0

#define LWIP_NETCONN                    0

#define LWIP_STATS                      0

#define ICMP_STATS                      0

/*
   ---------------------------------------
   ---------- Debugging options ----------
   ---------------------------------------
*/

/**
 * TCP_DEBUG: Enable debugging for TCP.
 */
#define TCP_DEBUG                       LWIP_DBG_ON
