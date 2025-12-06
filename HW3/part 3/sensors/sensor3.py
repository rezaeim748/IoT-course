import time
import random
import paho.mqtt.client as mqtt

broker_address = "127.0.0.1"
port = 1883

client = mqtt.Client("Sensor3")

client.connect(broker_address, port)

while True:
    wind_speed = random.uniform(5, 15)

    client.publish("topic/sensor3/wind_speed", f"{wind_speed:.2f}")

    time.sleep(10)
