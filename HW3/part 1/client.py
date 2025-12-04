import asyncio
import random
from aiocoap import *

async def main():
    context = await Context.create_client_context()
    alarm_state = random.choice([True, False])
    print("alarm state = %s"%(alarm_state))
    payload = b"OFF"

    if alarm_state:
        payload = b"ON"

    request = Message(code=POST, payload=payload, uri="coap://localhost/alarm")
    

    response = await context.request(request).response
    print('Result for POST: %s\n%r'%(response.code, response.payload))

    request = Message(code=GET, uri="coap://localhost/alarm")
    response = await context.request(request).response
    print('Result for GET: %s\n%r'%(response.code, response.payload))

if __name__ == "__main__":
    asyncio.get_event_loop().run_until_complete(main())
