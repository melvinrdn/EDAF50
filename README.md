# usenet_project, a C++ project

A mini Usenet-like news system in C++17, with two database modes:

Memory: in-memory only, resets on each run.
Disk: persistent on-disk storage using std::filesystem.

## Build

```bash
make
```

## Install

```bash
make install
```

## Clean

```bash
make clean
```

## Usage

### Server

```bash
./news_server <port> [--disk]
```

### Client

```bash
./news_client <host> <port>
```

## Testing

Run the provided Java test suites to verify protocol compliance:

```bash
java -jar TestServer1.jar <host> <port>
java -jar TestServer2.jar <host> <port>
```
