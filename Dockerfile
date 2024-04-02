# Użyj obrazu bazowego Ubuntu
FROM ubuntu:latest

WORKDIR /app

COPY . .

RUN apt-get update && apt-get install -y \
    cmake \
    gcc \
    g++ \
    gnat

RUN cmake .

RUN make

CMD ["./moritat"]
