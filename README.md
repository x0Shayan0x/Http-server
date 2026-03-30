# HTTP Server in C

A minimal HTTP server written from scratch in C. Binds to `localhost:3000` and responds to requests with a plain HTML page — no libraries, no frameworks, just raw sockets and the C standard library.

---

## 📁 Project Structure

```
http-server/
├── Server.h       # Server struct definition and function declarations
├── Server.c       # Socket setup, bind, listen, accept, and HTTP response logic
└── test.c         # Entry point — initialises and runs the server
```

---

### Prerequisites

- GCC or any C99-compatible compiler
- Linux / macOS (uses POSIX sockets)

### Build

```bash
gcc test.c Server.c -o server
```

### Run

```bash
./server
```

Then open your browser and navigate to:

```
http://localhost:3000
```

You should see:

```
Hello, World!
```

---

## 🔧 How It Works

1. **Socket creation** — opens a TCP socket with `socket()`
2. **Bind** — binds to `127.0.0.1:3000` with `bind()`
3. **Listen** — marks the socket as passive with `listen()`
4. **Accept loop** — blocks on `accept()`, handling one connection at a time
5. **HTTP response** — writes a minimal valid HTTP/1.1 response with a `Content-Type: text/html` header and an `<h1>Hello, World!</h1>` body
6. **Close** — closes the connection socket and loops back to accept the next request
