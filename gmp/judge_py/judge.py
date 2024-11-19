import requests

# APIのエンドポイント
api_url = "https://api.pi.delivery/v1/pi"

# パラメータの設定
start = 200000000 - 1000 + 1  # 取得開始位置
number_of_digits = 1000  # 取得する桁数

# APIリクエストのURL
request_url = f"{api_url}?start={start}&numberOfDigits={number_of_digits}"

# APIリクエストを送信
response = requests.get(request_url)

# レスポンスのチェック
if response.status_code == 200:
    data = response.json()
    pi_digits_api = data.get("content", "")
    print(f"google: {pi_digits_api}")
    
    # pi.txtファイルの読み込み
    try:
        with open("../kika/pi.txt", "r") as file:
            pi_digits_file = file.read().replace('\n', '').strip()
            
            # 指定開始位置からの桁を抽出
            if len(pi_digits_file) >= start + number_of_digits:
                pi_digits_from_file = pi_digits_file[start:start + number_of_digits]
            else:
                pi_digits_from_file = pi_digits_file[start:]
            
            print(f"pi.txt: {pi_digits_from_file}")
            
            # 比較
            if pi_digits_api == pi_digits_from_file:
                print('\n')
                print("APIのデータとファイルのデータは一致しています。")
            else:
                print('\n')
                print("APIのデータとファイルのデータは一致していません。")
    except FileNotFoundError:
        print("pi.txtファイルが見つかりません。")
else:
    print(f"エラーが発生しました: {response.status_code}")
