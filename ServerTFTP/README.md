# TFTP File Transfer Lab via Cisco Catalyst 2960-X

## Overview
Questo progetto documenta la configurazione, la verifica e le procedure di risoluzione dei problemi (*troubleshooting*) per lo stabilimento di un trasferimento file tramite protocollo **TFTP (Trivial File Transfer Protocol)** tra due host Windows, interconnessi mediante uno switch gestito **Cisco Catalyst 2960-X**.

---

## Topology & Network Specifications

| Componente | Dispositivo / Dettaglio | Indirizzo IP / Subnet | Interfaccia Switch |
| :--- | :--- | :--- | :--- |
| **Server TFTP** | PC Windows (Tftpd64 Server) | `192.168.1.10 /24` | `GigabitEthernet1/0/1` |
| **Client TFTP** | PC Windows (Tftpd32 Client) | `192.168.1.20 /24` | `GigabitEthernet1/0/2` |
| **Switch L2** | Cisco Catalyst 2960-X | N/A (VLAN 1 Default) | Ports `Gi1/0/1 - Gi1/0/2` |

---

## Switch Configuration (Cisco IOS)

L'infrastruttura di Livello 2 è stata configurata per garantire la connettività di rete trasparente sulla **VLAN 1**.

```text
Switch# configure terminal
Switch(config)# interface range gi1/0/1 - 2
Switch(config-if-range)# switchport mode access
Switch(config-if-range)# switchport access vlan 1
Switch(config-if-range)# no shutdown
Switch(config-if-range)# end
Switch# copy running-config startup-config
