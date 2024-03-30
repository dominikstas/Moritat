FROM ubuntu:latest

WORKDIR /app

COPY . .

RUN apt-get update && apt-get install -y \
    cmake 

RUN cmake .

RUN make

CMD ["./moritat"]
