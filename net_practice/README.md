*This project has been created as part of the 42 curriculum by <login>.*

# NetPractice

## Description
NetPractice is a practical networking project that trains the basics of computer networking using a browser-based simulator.  
The goal is to fix non-working network diagrams by configuring IP addresses, subnet masks, and default gateways so that devices can communicate through routers.

In this project, I completed 10 levels (10 exercises). Each level produces an exported configuration file that must be submitted in this repository.

## Instructions

### 1) Run the training interface
1. Download the NetPractice archive from the project page and extract it.
2. Open a terminal in the extracted folder.
3. Start the interface:
   - Preferred:
     - `./run.sh`
   - If `run.sh` does not work:
     - `python3 -m http.server 49242`
     - Open in your browser: `http://localhost:49242`

### 2) Important: enter your login
In the web interface, enter your 42 login in the provided field to use your personal configuration (required for proper submission/evaluation workflow).

### 3) Solve levels and export configs
1. Open a level.
2. Modify only the unshaded fields until the objectives are satisfied.
3. Click **Check again** to validate.
4. After a level is correct, click **Get my config** to export your configuration file.
5. Repeat until you complete **10 levels**.

### 4) Submission requirements
- You must submit **10 exported configuration files (one per level)**.
- These 10 files must be placed **at the root of the Git repository** (same folder as this README).

## Resources

### Networking concepts covered
- IPv4 addressing
- Subnet masks and CIDR notation
- Network / broadcast addresses
- Default gateway
- Routing basics (how hosts reach other networks)
- Routers vs switches (roles in a network)
- OSI / TCP-IP model overview (where IP addressing and routing fit)

### Classic references
- TCP/IP addressing and subnetting (CIDR): RFC 4632
- IPv4 addressing architecture: RFC 791
- Subnetting practice and explanations: online subnetting guides (CIDR, masks, gateways)
- OSI model overview: networking textbooks / vendor introductions (Cisco/Juniper learning materials)

### AI usage
I used AI to:
- Explain subnet masks, CIDR, and how to compute network/broadcast ranges.
- Double-check my reasoning when selecting valid host IP ranges and gateways.
- Summarize networking concepts (router, switch, default gateway, routing) for my README.

All final configurations were produced by me inside the NetPractice interface, and I verified each level using the built-in **Check again** validation before exporting the config.