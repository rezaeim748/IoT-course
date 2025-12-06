import time
import random
import paho.mqtt.client as mqtt

broker_address = "127.0.0.1"
port = 1883

client = mqtt.Client("Sensor2")

client.connect(broker_address, port)

while True:
    pressure = random.uniform(900, 1100)

    client.publish("topic/sensor2/pressure", f"{pressure:.2f}")

    time.sleep(7)
