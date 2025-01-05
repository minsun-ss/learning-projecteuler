FROM alpine:latest

RUN apk add --no-cache gcc g++ make cmake

WORKDIR /app
COPY . .
