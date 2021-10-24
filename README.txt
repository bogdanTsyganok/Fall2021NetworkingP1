Networking Project 1

Github link: https://github.com/bogdanTsyganok/Fall2021NetworkingP1.git

Video link:


Build Instructions if not working from git:
1. Clone repository
2. Open solution
3. Set configuration to x86
4. Open solution properties
5. Select "Multiple startup projects"
6. Arrange in order StaticBufferLibrary -> Server -> Client
7. In client and server properties under VC++ directories add   
   $(SolutionDir)StaticBufferLibrary to the Include Directories for x86 Debug/Release
   if it is not there.
8. Right click select Build dependencies -> Project dependencies for both client and server and set "Depends on StaticBufferLibrary" if it is not selected
9. Allow access to network if windows firewall asks


Client Commands:
/name "New Name" :			Set new display name (no quotation marks)"
/join "Room Name" :			Join a room or create it if the name isn't in use (no quotation marks)
/leave "Room Name" :			Leave a room (no quotation marks)
/message [Room Name] "Message" :	Send a message to a room (Square brackets around room name required, quotations are not)
/help :					Re-display this help text

Protocol Structure:
Header
[Packet Length][Command id]

Send Message
[Header][Length][User name][Length][Room Name][Length][Message]

Receive Message
[Header][Length][Room Name][Length][Message]
Join Room
[Header][Length][Room Name]

Leave Room
[Header][Length][Room Name]